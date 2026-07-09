/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "ConfigManager.h"
#include <regex>

using namespace sys::thread;

ConfigManager::ConfigManager() {
	setLoggingName("ConfigManager");
#ifdef DEBUG_CONFIGMANAGER
	setLogLevel(Logger::DEBUG);
#else // DEBUG_CONFIGMANAGER
	setLogLevel(Logger::INFO);
#endif // DEBUG_CONFIGMANAGER
}

ConfigManager::~ConfigManager() {
	clearConfigData();
}

bool ConfigManager::loadConfigData() {
	Locker guard(&mutex);

	logChanges = false;

	if (configStartTime.getStartTime() != 0)
		configStartTime.stop();

	configStartTime.start();

	if (!lua.runFile("conf/config.lua")) {
		fatal("ConfigManager failed to parse conf/config.lua");
		return false;
	}

	File file("conf/config-local.lua");

	if (file.setReadOnly()) {
		if (!lua.runFile("conf/config-local.lua")) {
			error("ConfigManager failed to parse conf/config-local.lua");
			return false;
		}
	} else {
		info("Did not find conf/config-local.lua", true);
	}

#ifdef DEBUG_CONFIGMANAGER
	info("Loaded config file(s) in " + String::valueOf(getConfigDataAgeMs()) + "ms", true);
#endif // DEBUG_CONFIGMANAGER

	bool resultGlobal, resultCore3;

	clearConfigData();

	// Load new-style "Core3.value" settings
	LuaObject core3 = lua.getGlobalObject("Core3");

	resultCore3 = parseConfigData("Core3");

	if (!resultCore3)
		error("Failed to parse Core3 configuration table, falling back on old Globals style config.");

	core3.pop();

	// Load legacy "globals" style configuration
	lua_State* L = lua.getLuaState();

	lua_pushglobaltable(L);

	resultGlobal = parseConfigData("Core3", true);

	if (!resultGlobal)
		error("Failed to parse legacy configuration globals.");

	lua_pop(L, 1);

	// Load file based strings into config
	setStringFromFile("Core3.MOTD", "conf/motd.txt");
	setStringFromFile("Core3.Revision", "conf/rev.txt");

#ifdef DEBUG_CONFIGMANAGER
	info("Parsed config into memory in " + String::valueOf(getConfigDataAgeMs()) + "ms", true);
	setString("Core3.ConfigManagerDebug", "Test1");
	setString("Core3.ConfigManagerDebug", "Compiled with DEBUG_CONFIGMANAGER");
	dumpConfig();
#endif // DEBUG_CONFIGMANAGER

	logChanges = true;

	return resultGlobal || resultCore3;
}

void ConfigManager::clearConfigData() {
	Locker guard(&mutex);

	for (int i = 0; i < configData.size(); ++i) {
		auto entry = configData.getUnsafe(i).getValue();
		delete entry;
	}

	configData.removeAll();
	configData.setNoDuplicateInsertPlan();
	incrementConfigVersion();
}

void ConfigManager::dumpConfig(bool includeSecure) {
	ReadLocker guard(&mutex);

	uint64 age = getConfigDataAgeMs() / 1000;

	info(true) << "dumpConfig: START (Config Age: " << age << " s, Version#:" << getConfigVersion() << ")";

	String hottestKey;
	int maxPS = 0;
	int maxUsageCounter = 0;

	for (int i = 0; i < configData.size(); ++i) {
		auto entry = configData.elementAt(i);
		String key = entry.getKey();
		ConfigDataItem* itm = entry.getValue();

		String stringVal = itm->toString();

		if (!includeSecure && isSensitiveKey(key)) {
			stringVal = "*******";
		}

		auto msg = info(true);

		int ps = age > 0 ? itm->getUsageCounter() / age : 0;

		if (ps > maxPS || itm->getUsageCounter() > maxUsageCounter) {
			hottestKey = String(key);
			maxPS = ps;
			maxUsageCounter = itm->getUsageCounter();
		}

		msg << key
			<< " usageCounter: " << itm->getUsageCounter()
			<< " (" << ps << "/s)"
			<< " bool: " << itm->getBool()
			<< " int: " << itm->getInt()
			<< " float: " << itm->getFloat()
			<< " str: '" << stringVal.escapeString()
			<< "'";

		msg.flush();
	}

	if (!hottestKey.isEmpty()) {
		info(true) << "Hottest key: " <<
		       	hottestKey << " usageCounter: " << maxUsageCounter << " (" << maxPS << "/s)";
	}

	auto engineConfig = Core::getPropertiesString();

	info(true) << engineConfig;

	info("dumpConfig: END", true);
}

bool ConfigManager::parseConfigData(const String& prefix, bool isGlobal, int maxDepth) {
	lua_State* L = lua.getLuaState();

	// Enter with table on top of lua stack
	if (!lua_istable(L, -1)) {
#ifdef DEBUG_CONFIGMANAGER
		error("Configuration error, expected table in ConfigManager::parseConfigData, prefix=" + prefix);
#endif // DEBUG_CONFIGMANAGER
		return false;
	}

	lua_pushnil(L); // First key

	bool isArray = true;

	// Crude array detection, is there a better way?
	for (int i = 0; lua_next(L, -2) != 0; ++i) {
		// -2 = key -1 = value
		int luaType = lua_type(L, -2);
		lua_pop(L, 1);

		if (luaType == LUA_TSTRING) {
			isArray = false;
			lua_pop(L, 1);
			break;
		}
	}

	if (isArray) {
		Vector <ConfigDataItem *>* elements = new Vector <ConfigDataItem *>();

		lua_pushnil(L); // First key

		for (int i = 0; lua_next(L, -2) != 0; ++i) {
			// -2 = key -1 = value

			int luaType = lua_type(L, -1);

			switch (luaType) {
			case LUA_TBOOLEAN:
				elements->add(new ConfigDataItem((bool)lua_toboolean(L, -1)));
				break;

			case LUA_TNUMBER:
				elements->add(new ConfigDataItem((lua_Number)lua_tonumber(L, -1)));
				break;

			case LUA_TSTRING:
				elements->add(new ConfigDataItem((String)lua_tostring(L, -1)));
				break;

			default:
				error("parseConfigData: row #" + String::valueOf(i) + " " + prefix + " type: " + lua_typename(L, luaType) + " is not supported in an array.");
				lua_pop(L, 1);
				continue;
			}

			lua_pop(L, 1);
		}

		return updateItem(prefix, new ConfigDataItem(elements));
	}

	// Handle Tables
	lua_pushnil(L); // First key

	for (int i = 0; lua_next(L, -2) != 0; ++i) {
		// -2 = key -1 = value
		int luaType = lua_type(L, -2);

		// Only use the string keys
		if (luaType != LUA_TSTRING) {
			if (luaType != LUA_TNUMBER)
				info("Error initializing configuration key for row #" + String::valueOf(i) + "(" + lua_typename(L, luaType) + ") is not a string.", true);

			lua_pop(L, 1);
			continue;
		}

		String luaKey = lua_tostring(L, -2);
		bool skipKey = false;

		// Ignore keys starting with underscore
		if (luaKey.subString(0, 1) == '_')
			skipKey = true;

		if (isGlobal) {
			// Avoid well known lua names
			if (luaKey.indexOf("Core3") == 0 || luaKey.subString(0, 1).toLowerCase() == luaKey.subString(0, 1))
				skipKey = true;
		}

		if (skipKey) {
			lua_pop(L, 1);
			continue;
		}

		String key = prefix + "." + luaKey;
		luaType = lua_type(L, -1);

		switch (luaType) {
		case LUA_TBOOLEAN:
			setBool(key, lua_toboolean(L, -1));
			break;

		case LUA_TNUMBER:
			setNumber(key, lua_tonumber(L, -1));
			break;

		case LUA_TSTRING:
			setString(key, lua_tostring(L, -1));
			break;

		case LUA_TTABLE:
			if (maxDepth <= 0) {
				error("Configuration error, reached max depth in ConfigManager::parseConfigData, prefix=" + prefix);
			} else if (!parseConfigData(key, isGlobal, maxDepth - 1)) {
				lua_pop(L, 1);
				return false;
			}
			lua_pop(L, 1);
			continue;

		case LUA_TFUNCTION:
			if (isGlobal) {
				lua_pop(L, 1);
				continue;
			}

			// [[fallthrough]];

		default:
			error("parseConfigData: row #" + String::valueOf(i) + " " + key + " type: " + lua_typename(L, luaType) + " is not supported");
			lua_pop(L, 1);
			continue;
		}

		lua_pop(L, 1);
	}

	return true;
}

bool ConfigManager::parseConfigJSONRecursive(const String prefix, JSONSerializationType jsonNode, String& errorMessage, bool updateOnly) {
	for (auto jsonData = jsonNode.begin(); jsonData != jsonNode.end(); ++jsonData) {
		String key = (prefix.isEmpty() ? "" : prefix + ".") + jsonData.key();

		if (jsonData->is_array()) {
			if (updateOnly && !contains(key)) {
				errorMessage = "Array key " + key + " doesn't exist.";
				error() << "parseConfigJSONRecursive(" << key << "): " << errorMessage;
				return false;
			}

			bool isValid = true;
			Vector <ConfigDataItem *>* elements = new Vector <ConfigDataItem *>();

			for (auto jsonElement = jsonData->begin();isValid && jsonElement != jsonData->end(); ++jsonElement) {
				switch (jsonElement->type()) {
				case JSONSerializationType::value_t::boolean:
					elements->add(new ConfigDataItem((bool)jsonElement.value().get<bool>()));
					break;

				case JSONSerializationType::value_t::number_float:
				case JSONSerializationType::value_t::number_unsigned:
				case JSONSerializationType::value_t::number_integer:
					elements->add(new ConfigDataItem((lua_Number)jsonElement.value().get<double>()));
					break;

				case JSONSerializationType::value_t::string:
					elements->add(new ConfigDataItem(jsonElement.value().get<std::string>()));
					break;

				default:
					isValid = false;
					errorMessage = "Failed to parse json type " + String(jsonElement->type_name()) + " into array " + key;
					error() << "parseConfigJSONRecursive(" << key << "): " << errorMessage;
					break;
				}
			}

			if (isValid && !updateItem(key, new ConfigDataItem(elements))) {
				isValid = false;
			}

			if (!isValid) {
				delete elements;
				return false;
			}

			continue;
		}

		if (jsonData->is_object()) {
			if (!parseConfigJSONRecursive(key, jsonData.value(), errorMessage, updateOnly)) {
				return false;
			}
			continue;
		}

		if (updateOnly && !contains(key)) {
			errorMessage = "Key " + key + " doesn't exist.";
			error() << "parseConfigJSONRecursive(" << key << "): " << errorMessage;
			return false;
		}

		switch (jsonData->type()) {
		case JSONSerializationType::value_t::boolean:
			setBool(key, jsonData.value().get<bool>());
			break;

		case JSONSerializationType::value_t::number_float:
		case JSONSerializationType::value_t::number_unsigned:
		case JSONSerializationType::value_t::number_integer:
			setNumber(key, (lua_Number)jsonData.value().get<double>());
			break;

		case JSONSerializationType::value_t::string:
			setString(key, jsonData.value().get<std::string>());
			break;

		default:
			errorMessage = "Failed to parse json type " + String(jsonData->type_name()) + " into " + key;
			error() << "parseConfigJSONRecursive(" << key << "): " << errorMessage;
			return false;
			break;
		}
	}

	return true;
}

bool ConfigManager::parseConfigJSON(const JSONSerializationType jsonData, String& errorMessage, bool updateOnly) {
	Locker guard(&mutex);

	try {
		return parseConfigJSONRecursive("", jsonData, errorMessage, updateOnly);
	} catch (const JSONSerializationType::exception& e) {
		errorMessage = "Exception while parsing json:" + String(e.what()) + "(" + e.id + ")";
		error() << "parseConfigJSON: " << errorMessage;
	} catch (const Exception& e) {
		errorMessage = "Exception while parsing config:" + e.getMessage();
		error() << "parseConfigJSON: " << errorMessage;
	} catch (...) {
		StringBuffer err;
		err << "Uncaptured exception parsing config"
#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
			<< ": " << __cxxabiv1::__cxa_current_exception_type()->name()
#endif
			<< ".";
		errorMessage = err.toString();
		error() << "parseConfigJSON: " << errorMessage;
	}

	return false;
}

bool ConfigManager::parseConfigJSON(const String& jsonString, String& errorMessage, bool updateOnly) {
	Locker guard(&mutex);

	try {
		JSONSerializationType jsonData = JSONSerializationType::parse(jsonString);
		return parseConfigJSONRecursive("", jsonData, errorMessage, updateOnly);
	} catch (const JSONSerializationType::exception& e) {
		errorMessage = "Exception while parsing json:" + String(e.what()) + "(" + e.id + ")";
		error() << "parseConfigJSON(" << jsonString << "): " << errorMessage;
	} catch (const Exception& e) {
		errorMessage = "Exception while parsing config:" + e.getMessage();
		error() << "parseConfigJSON(" << jsonString << "): " << errorMessage;
	} catch (...) {
		StringBuffer err;
		err << "Uncaptured exception parsing config"
#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
			<< ": " << __cxxabiv1::__cxa_current_exception_type()->name()
#endif
			<< ".";
		errorMessage = err.toString();
		error() << "parseConfigJSON(" << jsonString << "): " << errorMessage;
	}

	return false;
}

bool ConfigManager::contains(const String& name, unsigned int accountID) const {
	return configData.find(name) != -1 || configData.find(withAccount(name, accountID)) != -1;
}

ConfigDataItem* ConfigManager::findItem(const String& name, unsigned int accountID) const {
	int pos = -1;

	if (pos == -1 && accountID > 0) {
		pos = configData.find(withAccount(name, accountID));
	}

	if (pos == -1) {
		pos = configData.find(name);
	}

	if (pos == -1) {
		return nullptr;
	}

	return configData.get(pos);
}

int ConfigManager::getUsageCounter(const String& name) const {
	ConfigDataItem* itm = findItem(name);

	if (itm == nullptr) {
		return -1;
	}

	return itm->getUsageCounter();
}

int ConfigManager::getInt(const String& name, int defaultValue, unsigned int accountID) {
	ReadLocker guard(&mutex);

	ConfigDataItem* itm = findItem(name, accountID);

	if (itm == nullptr)
		return defaultValue;

	return itm->getInt();
}

bool ConfigManager::getBool(const String& name, bool defaultValue, unsigned int accountID) {
	ReadLocker guard(&mutex);

	ConfigDataItem* itm = findItem(name, accountID);

	if (itm == nullptr)
		return defaultValue;

	return itm->getBool();
}

float ConfigManager::getFloat(const String& name, float defaultValue, unsigned int accountID) {
	ReadLocker guard(&mutex);

	ConfigDataItem* itm = findItem(name, accountID);

	if (itm == nullptr)
		return defaultValue;

	return itm->getFloat();
}

const String& ConfigManager::getString(const String& name, const String& defaultValue, unsigned int accountID) {
	Locker guard(&mutex);

	ConfigDataItem* itm = findItem(name, accountID);

	if (itm == nullptr) {
		itm = new ConfigDataItem(defaultValue);
		if (itm == nullptr || !updateItem(name, itm))
			throw Exception("ConfigManager::getString(" + name + ") failed to set default value: [" + defaultValue + "]");
	}

	return itm->getString();
}

const Vector<String>& ConfigManager::getStringVector(const String& name, unsigned int accountID) {
	ReadLocker guard(&mutex);

	ConfigDataItem* itm = findItem(name, accountID);

	if (itm == nullptr)
		throw Exception("ConfigManager::getStringVector(" + name + ") not found");

	return itm->getStringVector();
}

const SortedVector<String>& ConfigManager::getSortedStringVector(const String& name, unsigned int accountID) {
	ReadLocker guard(&mutex);

	ConfigDataItem* itm = findItem(name, accountID);

	if (itm == nullptr)
		throw Exception("ConfigManager::getSortedStringVector(" + name + ") not found");

	return itm->getSortedStringVector();
}

const Vector<int>& ConfigManager::getIntVector(const String& name, unsigned int accountID) {
	ReadLocker guard(&mutex);

	ConfigDataItem* itm = findItem(name, accountID);

	if (itm == nullptr)
		throw Exception("ConfigManager::getIntVector(" + name + ") not found");

	return itm->getIntVector();
}

bool ConfigManager::isSensitiveKey(const String& key) {
	auto lcKey = key.toLowerCase();

	return lcKey.contains("secret") || lcKey.contains("pass") || lcKey.contains("token");
}

void ConfigManager::writeJSONPath(StringTokenizer& tokens, JSONSerializationType& jsonData, const JSONSerializationType& jsonValue) {
	String nextName;
	tokens.getStringToken(nextName);

	if (tokens.hasMoreTokens()) {
		if (jsonData[nextName].is_null()) {
			jsonData[nextName] = JSONSerializationType::object();
		}
		writeJSONPath(tokens, jsonData[nextName], jsonValue);
	} else {
		jsonData[nextName] = jsonValue;
	}
}

bool ConfigManager::getAsJSON(const String& target, JSONSerializationType& jsonData) {
	ReadLocker guard(&mutex);

	try {
		auto re = std::regex((target + "(?:\\..*$|$)").toCharArray());
		jsonData = JSONSerializationType::object();

		for (int i = 0; i < configData.size(); ++i) {
			JSONSerializationType jsonValue;
			auto entry = configData.elementAt(i);
			String key = entry.getKey();

			if (isSensitiveKey(key)) {
				jsonValue = "*******";
			} else {
				ConfigDataItem* itm = entry.getValue();
				itm->getAsJSON(jsonValue);
			}

			if (std::regex_search(key.toCharArray(), re)) {
				StringTokenizer tokenizer(key);
				tokenizer.setDelimeter(".");
				writeJSONPath(tokenizer, jsonData, jsonValue);
			}
		}
	} catch(...) {
		return false;
	}

	return true;
}

bool ConfigManager::updateItem(const String& name, ConfigDataItem* newItem) {
	Locker guard(&mutex);

	if (newItem == nullptr || name.isEmpty())
		return false;

	int pos = configData.find(name);

	if (pos != -1) {
		ConfigDataItem* oldItem = configData.get(pos);
		configData.drop(name);
		delete oldItem;
		oldItem = nullptr;
	}

	if (logChanges) {
		if (isSensitiveKey(name)) {
			info(true) << "Configuration updated: " << name;
		} else {
			info(true) << "Configuration update: " << name << " = [" << newItem->toString() << "]";
		}
	}

#ifdef DEBUG_CONFIGMANAGER
	info("updateItem: " + name + " = [" + newItem->toString() + "]", true);
	newItem->setDebugTag(name);
#endif // DEBUG_CONFIGMANAGER

	configData.put(std::move(name), std::move(newItem));
	incrementConfigVersion();
	return true;
}

bool ConfigManager::setNumber(const String& name, lua_Number newValue) {
	return updateItem(name, new ConfigDataItem(newValue));
}

bool ConfigManager::setInt(const String& name, int newValue) {
	return updateItem(name, new ConfigDataItem(newValue));
}

bool ConfigManager::setBool(const String& name, bool newValue) {
	return updateItem(name, new ConfigDataItem(newValue));
}

bool ConfigManager::setFloat(const String& name, float newValue) {
	return updateItem(name, new ConfigDataItem(newValue));
}

bool ConfigManager::setString(const String& name, const String& newValue) {
	return updateItem(name, new ConfigDataItem(newValue));
}

bool ConfigManager::setStringFromFile(const String& name, const String& fileName) {
	StringBuffer newValue;

	try {
		File file(fileName);
		FileReader reader(&file);
		String line;

		while (reader.readLine(line))
			newValue << line;

		reader.close();

		return setString(name, newValue.toString());
	} catch (const FileNotFoundException& e) {
		error("setStringFromFile(" + name + ", " + fileName +") File Not Found.");
	} catch (const Exception& e) {
		error("setStringFromFile(" + name + ", " + fileName +") Unexpected exception reading file.");
	}

	return false;
}

void ConfigManager::incrementConfigVersion() {
	configVersion.increment();
}

String ConfigManager::withAccount(const String& name, unsigned int accountID) const {
	if (accountID == 0) {
		return name;
	}

	StringBuffer acctFlag;
	acctFlag << "Core3.AccountFlags." << accountID << "." << name;

	return acctFlag.toString();
}

uint64 ConfigManager::getConfigDataAgeMs() const {
	return configStartTime.elapsedMs();
}

int ConfigManager::getConfigVersion() {
	return configVersion.get();
}

Logger::LogLevel ConfigManager::getLogLevel(const String& name, Logger::LogLevel defaultValue, unsigned int accountID) {
	return static_cast<Logger::LogLevel>(getInt(name, (int)defaultValue, accountID));
}

// Legacy getters
bool ConfigManager::getMakeLogin() {
	return getBool("Core3.MakeLogin", true);
}

bool ConfigManager::getMakeZone() {
	return getBool("Core3.MakeZone", true);
	;
}

bool ConfigManager::getMakePing() {
	return getBool("Core3.MakePing", true);
}

bool ConfigManager::getMakeStatus() {
	return getBool("Core3.MakeStatus", true);
}

bool ConfigManager::getDumpObjFiles() {
	return getBool("Core3.DumpObjFiles", true);
}

bool ConfigManager::shouldUnloadContainers() {
	// Use cached value as this is called often
	static uint32 cachedVersion = 0;
	static bool cachedUnloadContainers;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedUnloadContainers = getBool("Core3.UnloadContainers", true);
		cachedVersion = configVersion.get();
	}

	return cachedUnloadContainers;
}

bool ConfigManager::shouldUseMetrics() {
	// On Basilisk this is called 400/s
	static uint32 cachedVersion = 0;
	static bool cachedUseMetrics;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedUseMetrics = getBool("Core3.UseMetrics", false);
		cachedVersion = configVersion.get();
	}

	return cachedUseMetrics;
}

bool ConfigManager::getPvpMode() {
	// Use cached value as this is a hot item called in:
	//   CreatureObjectImplementation::isAttackableBy
	//   CreatureObjectImplementation::isAggressiveTo
	static uint32 cachedVersion = 0;
	static bool cachedPvpMode;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedPvpMode = getBool("Core3.PvpMode", false);
		cachedVersion = configVersion.get();
	}

	return cachedPvpMode;
}

bool ConfigManager::setPvpMode(bool val) {
	return setBool("Core3.PvpMode", val);
}

const String& ConfigManager::getORBNamingDirectoryAddress() {
	return getString("Core3.ORB", "");
}

uint16 ConfigManager::getORBNamingDirectoryPort() {
	return getInt("Core3.ORBPort", 44419);
}

const String& ConfigManager::getDBHost() {
	return getString("Core3.DBHost", "127.0.0.1");
}

bool ConfigManager::isProgressMonitorActivated() {
	// Use cached value as this a hot item called in lots of loops
	static uint32 cachedVersion = 0;
	static bool cachedProgressMonitors;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedProgressMonitors = getBool("Core3.ProgressMonitors", false);
		cachedVersion = configVersion.get();
	}

	return cachedProgressMonitors;
}

bool ConfigManager::includeFactionPetsForMissionDifficulty() {
	// Use cached value as this a hot item called in lots of loops
	static uint32 cachedVersion = 0;
	static bool cachedValue;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedValue = getBool("Core3.MissionManager.IncludeFactionPets", true);
		cachedVersion = configVersion.get();
	}

	return cachedValue;
}

int ConfigManager::getDBPort() {
	return getInt("Core3.DBPort", 3306);
}

const String& ConfigManager::getDBName() {
	return getString("Core3.DBName", "swgemu");
}

const String& ConfigManager::getDBUser() {
	return getString("Core3.DBUser", "root");
}

const String& ConfigManager::getDBPass() {
	return getString("Core3.DBPass", "Gemeni1");
}

const String& ConfigManager::getDBSecret() {
	return getString("Core3.DBSecret", "swgemusecret");
}

const String& ConfigManager::getMantisHost() {
	return getString("Core3.MantisHost", "127.0.0.1");
}

int ConfigManager::getMantisPort() {
	return getInt("Core3.MantisPort", 3306);
}

const String& ConfigManager::getLatestTre() {
	return getString("Core3.TreManager.LatestTre", "default_patch.tre");
}

const Vector<String>& ConfigManager::getTreFiles() {
	return getStringVector("Core3.TreFiles");
}

const String& ConfigManager::getMantisName() {
	return getString("Core3.MantisName", "swgemu");
}

const String& ConfigManager::getMantisUser() {
	return getString("Core3.MantisUser", "root");
}

const String& ConfigManager::getMantisPass() {
	return getString("Core3.MantisPass", "Gemeni1");
}

const String& ConfigManager::getMantisPrefix() {
	return getString("Core3.MantisPrfx", "");
}

const String& ConfigManager::getMessageOfTheDay() {
	return getString("Core3.MOTD", "Welcome to SWGEmu!");
}

const String& ConfigManager::getRevision() {
	return getString("Core3.Revision", "");
}

const String& ConfigManager::getMetricsHost() {
	return getString("Core3.MetricsHost", "127.0.0.1");
}

const String& ConfigManager::getMetricsPrefix() {
	return getString("Core3.MetricsPrefix", "");
}

int ConfigManager::getMetricsPort() {
	return getInt("Core3.MetricsPort", 8125);
}

const String& ConfigManager::getTrePath() {
	return getString("Core3.TrePath", "tre");
}

uint16 ConfigManager::getLoginPort() {
	return getInt("Core3.LoginPort", 44453);
}

uint16 ConfigManager::getStatusPort() {
	return getInt("Core3.StatusPort", 44455);
}

uint16 ConfigManager::getPingPort() {
	return getInt("Core3.PingPort", 44462);
}

const String& ConfigManager::getLoginRequiredVersion() {
	return getString("Core3.LoginRequiredVersion", "20050408-18:00");
}

int ConfigManager::getLoginProcessingThreads() {
	return getInt("Core3.LoginProcessingThreads", 1);
}

int ConfigManager::getLoginAllowedConnections() {
	return getInt("Core3.LoginAllowedConnections", 30);
}

int ConfigManager::getStatusAllowedConnections() {
	return getInt("Core3.StatusAllowedConnections", 100);
}

int ConfigManager::getPingAllowedConnections() {
	return getInt("Core3.PingAllowedConnections", 3000);
}

int ConfigManager::getStatusInterval() {
	return getInt("Core3.StatusInterval", 60);
}

int ConfigManager::getAutoReg() {
	return getBool("Core3.AutoReg", true);
}

int ConfigManager::getZoneProcessingThreads() {
	return getInt("Core3.ZoneProcessingThreads", 10);
}

int ConfigManager::getZoneAllowedConnections() {
	return getInt("Core3.ZoneAllowedConnections", 300);
}

int ConfigManager::getZoneGalaxyID() {
	return getInt("Core3.ZoneGalaxyID", 2);
}

int ConfigManager::getZoneServerPort() {
	return getInt("Core3.ZoneServerPort", 0);
}

const SortedVector<String>& ConfigManager::getEnabledZones() {
	return getSortedStringVector("Core3.ZonesEnabled");
}

const SortedVector<String>& ConfigManager::getEnabledSpaceZones() {
	return getSortedStringVector("Core3.SpaceZonesEnabled");
}

int ConfigManager::getPurgeDeletedCharacters() {
	return getInt("Core3.PurgeDeletedCharacters", 10); // In minutes
}

int ConfigManager::getMaxNavMeshJobs() {
	return getInt("Core3.MaxNavMeshJobs", 6);
}

int ConfigManager::getMaxAuctionSearchJobs() {
	return getInt("Core3.MaxAuctionSearchJobs", 1);
}

const String& ConfigManager::getLogFile() {
	return getString("Core3.LogFile", "log/core3.log");
}

int ConfigManager::getLogFileLevel() {
	return getInt("Core3.LogFileLevel", Logger::INFO);
}

int ConfigManager::getRotateLogSizeMB() {
	return getInt("Core3.RotateLogSizeMB", 100);
}

bool ConfigManager::getRotateLogAtStart() {
	return getBool("Core3.RotateLogAtStart", false);
}

void ConfigManager::setProgressMonitors(bool val) {
	setBool("Core3.ProgressMonitors", val);
}

const String& ConfigManager::getTermsOfService() {
	return getString("Core3.TermsOfService", "");
}

int ConfigManager::getTermsOfServiceVersion() {
	return getInt("Core3.TermsOfServiceVersion", 0);
}

bool ConfigManager::getJsonLogOutput() {
	return getBool("Core3.LogJSON", false);
}

bool ConfigManager::getSyncLogOutput() {
	return getBool("Core3.LogSync", false);
}

bool ConfigManager::getLuaLogJSON() {
	return getBool("Core3.LuaLogJSON", false);
}

bool ConfigManager::getPathfinderLogJSON() {
	return getBool("Core3.PathfinderLogJSON", false);
}

int ConfigManager::getCleanupMailCount() {
	return getInt("Core3.CleanupMailCount", 25000);
}

int ConfigManager::getRESTPort() {
	return getInt("Core3.RESTServerPort", 0);
}

const String& ConfigManager::getInactiveAccountTitle() {
	return getString("Core3.InactiveAccountTitle", "Account Disabled");
}

const String& ConfigManager::getInactiveAccountText() {
	return getString("Core3.InactiveAccountText", "The server administrators have disabled your account.");
}

bool ConfigManager::getCharacterBuilderEnabled() {
	return getBool("Core3.CharacterBuilderEnabled", false);
}

int ConfigManager::getPlayerLogLevel() {
	return getInt("Core3.PlayerLogLevel", Logger::INFO);
}

int ConfigManager::getMaxLogLines() {
	return getInt("Core3.MaxLogLines", 1000000);
}

int ConfigManager::getSessionStatsSeconds() {
	static uint32 cachedVersion = 0;
	static int cachedSessionStatsSeconds;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedSessionStatsSeconds = getInt("Core3.SessionStatsSeconds", 1800);
#ifndef WITH_DEV_MODE
		if (cachedSessionStatsSeconds < 300) {
			cachedSessionStatsSeconds = 300;
		} else if (cachedSessionStatsSeconds > 3600) {
			cachedSessionStatsSeconds = 3600;
		}
#endif // !WITH_DEV_MODE
		cachedVersion = configVersion.get();
	}

	return cachedSessionStatsSeconds;
}

int ConfigManager::getOnlineLogSeconds() {
	return getInt("Core3.OnlineLogSeconds", 300);
}

int ConfigManager::getOnlineLogSize() {
	static uint32 cachedVersion = 0;
	static int cachedOnlineLogSize;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedOnlineLogSize = getInt("Core3.OnlineLogSize", 100000000);
		cachedVersion = configVersion.get();
	}

	return cachedOnlineLogSize;
}

String ConfigManager::getNoTradeMessage() {
	static uint32 cachedVersion = 0;
	static String cachedNoTradeMessage;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedNoTradeMessage = getString("Core3.TangibleObject.NoTradeMessage", "");
		cachedVersion = configVersion.get();
	}

	return cachedNoTradeMessage;
}

String ConfigManager::getForceNoTradeMessage() {
	static uint32 cachedVersion = 0;
	static String cachedForceNoTradeMessage;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedForceNoTradeMessage = getString("Core3.TangibleObject.ForceNoTradeMessage", "");
		cachedVersion = configVersion.get();
	}

	return cachedForceNoTradeMessage;
}

String ConfigManager::getForceNoTradeADKMessage() {
	static uint32 cachedVersion = 0;
	static String cachedForceNoTradeADKMessage;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedForceNoTradeADKMessage = getString("Core3.TangibleObject.ForceNoTradeADKMessage", "");
		cachedVersion = configVersion.get();
	}

	return cachedForceNoTradeADKMessage;
}

uint32 ConfigManager::getAiAgentConsoleThrottle() {
	static uint32 cachedVersion = 0;
	static uint32 cachedValue;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
#ifdef DEBUG_AI
		cachedValue = getInt("Core3.AiAgent.ConsoleThrottle", 1);
#else  // !DEBUG_AI
		cachedValue = getInt("Core3.AiAgent.ConsoleThrottle", 100);
#endif // DEBUG_AI
		if (cachedVersion <= 0) {
			cachedVersion = 1;
		}

		cachedVersion = configVersion.get();
	}

	return cachedValue;
}

#ifdef DEBUG_AI
bool ConfigManager::getAiAgentLoadTesting() {
	static uint32 cachedVersion = 0;
	static bool cachedAiAgentLoadTesting;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedAiAgentLoadTesting = getBool("Core3.AiAgent.AiAgentLoadTesting", false);
		cachedVersion = configVersion.get();
	}

	return cachedAiAgentLoadTesting;
}
#endif // DEBUG_AI

bool ConfigManager::isPvpBroadcastChannelEnabled() {
	static uint32 cachedVersion = 0;
	static bool cachedPvpBroadcastChannel;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedPvpBroadcastChannel = getBool("Core3.ChatManager.PvpBroadcastChannel", false);
		cachedVersion = configVersion.get();
	}

	return cachedPvpBroadcastChannel;
}

bool ConfigManager::useCovertOvertSystem() {
	static uint32 cachedVersion = 0;
	static bool cachedCovertOvertSystem;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedCovertOvertSystem = getBool("Core3.GCWManager.useCovertOvertSystem", false);
		cachedVersion = configVersion.get();
	}

	return cachedCovertOvertSystem;
}

bool ConfigManager::getLoginEnableSessionId() {
	static uint32 cachedVersion = 0;
	static bool cachedEnableSessionId;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedEnableSessionId = getBool("Core3.Login.EnableSessionId", false);
		cachedVersion = configVersion.get();
	}

	return cachedEnableSessionId;
}

int ConfigManager::getMinLairSpawnInterval() {
	static uint32 cachedVersion = 0;
	static int cachedMinSpawnDelay;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedMinSpawnDelay = getInt("Core3.Regions.minimumLairSpawnInterval", 5000);
		cachedVersion = configVersion.get();
	}

	return cachedMinSpawnDelay;
}

int ConfigManager::getMinSpaceSpawnInterval() {
	static uint32 cachedVersion = 0;
	static int cachedMinSpaceSpawnDelay;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedMinSpaceSpawnDelay = getInt("Core3.Regions.minimumSpaceSpawnInterval", 5000);
		cachedVersion = configVersion.get();
	}

	return cachedMinSpaceSpawnDelay;
}

bool ConfigManager::disableWorldSpawns() {
	static uint32 cachedVersion = 0;
	static bool cachedDisableWorldSpawns;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedDisableWorldSpawns = getBool("Core3.Regions.DisableWorldSpawns", false);
		cachedVersion = configVersion.get();
	}

	return cachedDisableWorldSpawns;
}

bool ConfigManager::disableSpaceSpawns() {
	static uint32 cachedVersion = 0;
	static bool cachedDisableSpaceSpawns;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedDisableSpaceSpawns = getBool("Core3.Regions.DisableSpaceSpawns", false);
		cachedVersion = configVersion.get();
	}

	return cachedDisableSpaceSpawns;
}

float ConfigManager::getSpawnCheckRange() {
	static uint32 cachedVersion = 0;
	static float cachedSpawnRange;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedSpawnRange = getFloat("Core3.Regions.spawnCheckRange", 64.f);
		cachedVersion = configVersion.get();
	}

	return cachedSpawnRange;
}

float ConfigManager::getSpaceSpawnCheckRange() {
	static uint32 cachedVersion = 0;
	static float cachedSpaceSpawnRange;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedSpaceSpawnRange = getFloat("Core3.Regions.spaceSpawnCheckRange", 1024.f);
		cachedVersion = configVersion.get();
	}

	return cachedSpaceSpawnRange;
}

bool ConfigManager::getLootDebugAttributes() {
	static uint32 cachedVersion = 0;
	static bool cachedValue;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedValue = getBool("Core3.LootManager.DebugAttributes", false);
		cachedVersion = configVersion.get();
	}

	return cachedValue;
}

/*

	JTL Configs

*/

bool ConfigManager::isJtlEnabled() {
	static uint32 cachedVersion = 0;
	static bool cachedJtlEnabled;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedJtlEnabled = getBool("Core3.JTL.JTLEnabled", false);
		cachedVersion = configVersion.get();
	}

	return cachedJtlEnabled;
}

bool ConfigManager::launchFromDevice() {
	static uint32 cachedVersion = 0;
	static bool cachedLaunchFromDevice;

	if (configVersion.get() > cachedVersion) {
		Locker guard(&mutex);
		cachedLaunchFromDevice = getBool("Core3.JTL.LaunchFromDevice", false);
		cachedVersion = configVersion.get();
	}

	return cachedLaunchFromDevice;
}

/*
** ConfigDataItem
*/

ConfigDataItem::ConfigDataItem(lua_Number value) {
	asNumber = value;
	asBool   = (bool)asNumber;
	asString = String::valueOf(value);
	asVector = nullptr;
	asStringVector = nullptr;
	asSortedStringVector = nullptr;
	usageCounter = 0;
}

ConfigDataItem::ConfigDataItem(int value) {
	asNumber = (lua_Number)value;
	asBool   = (bool)asNumber;
	asString = String::valueOf(value);
}

ConfigDataItem::ConfigDataItem(bool value) {
	asNumber = value ? 1.0f : 0.0f;
	asBool   = value;
	asString = String(value ? "true" : "false");
}

ConfigDataItem::ConfigDataItem(float value) {
	asNumber = (lua_Number)value;
	asBool   = (bool)asNumber;
	asString = String::valueOf(value);
}

ConfigDataItem::ConfigDataItem(const String& value) {
	if (value == "true") {
		asNumber = 1.0f;
		asBool = true;
	} else if (value == "false") {
		asNumber = 0.0f;
		asBool = false;
	} else {
		asNumber = atof(value.toCharArray());
		asBool = asNumber != 0.0 ? true : false;
	}
	asString = String(value);
}

ConfigDataItem::ConfigDataItem(Vector <ConfigDataItem *>* value) {
	asBool = true;
	asNumber = value->size();
	asString = String("<Vector " + String::valueOf((int)asNumber) + ">");
	asVector = value;
}

ConfigDataItem::~ConfigDataItem() {
#ifdef DEBUG_CONFIGMANAGER
	std::cout << "ConfigDataItem destroyed " << debugTag.toCharArray() << " usageCounter = " << usageCounter << std::endl << std::flush;
#endif // DEBUG_CONFIGMANAGER

	if (asVector != nullptr) {
		for (int i = 0;i < asVector->size(); ++i) {
			auto element = asVector->getUnsafe(i);
			delete element;
		}

		delete asVector;
		asVector = nullptr;
	}

	if (asStringVector != nullptr) {
		delete asStringVector;
		asStringVector = nullptr;
	}

	if (asSortedStringVector != nullptr) {
		delete asSortedStringVector;
		asSortedStringVector = nullptr;
	}

	if (asIntVector != nullptr) {
		delete asIntVector;
		asIntVector = nullptr;
	}
}

void ConfigDataItem::getAsJSON(JSONSerializationType& jsonData) {
	if (asVector != nullptr) {
		jsonData = JSONSerializationType::array();

		for (int i = 0;i < asVector->size(); i++) {
			JSONSerializationType jsonValue;
			ConfigDataItem* curItem = asVector->get(i);

			if (curItem == nullptr) {
				continue;
			}

			curItem->getAsJSON(jsonValue);
			jsonData.push_back(jsonValue);
		}

		return;
	}

	jsonData = asString;
}

bool ConfigDataItem::getBool() const {
	usageCounter.increment();
	return asBool;
}

float ConfigDataItem::getFloat() const {
	usageCounter.increment();
	return (float)asNumber;
}

int ConfigDataItem::getInt() const {
	usageCounter.increment();
	return (int)asNumber;
}

const String& ConfigDataItem::getString() const {
	usageCounter.increment();
	return asString;
}

const Vector<String>& ConfigDataItem::getStringVector() {
	Locker guard(&mutex);

	if (asStringVector == nullptr) {
		asStringVector = new Vector<String>();

		if (asStringVector == nullptr)
			throw Exception("Failed to allocate Vector<String> in getStringVector()");

		if (asVector == nullptr) {
			asStringVector->add(getString());
		} else {
			for (int i = 0; i < asVector->size(); i++) {
				ConfigDataItem* curItem = asVector->get(i);

				if (curItem == nullptr)
					continue;

				asStringVector->add(curItem->getString());
			}
		}
	}

	return *asStringVector;
}

const SortedVector<String>& ConfigDataItem::getSortedStringVector() {
	Locker guard(&mutex);

	if (asSortedStringVector == nullptr) {
		asSortedStringVector = new SortedVector<String>();
		auto entries = getStringVector();

		for (int i = 0; i < entries.size(); i++) {
			asSortedStringVector->add(entries.get(i));
		}
	}

	return *asSortedStringVector;
}

const Vector<int>& ConfigDataItem::getIntVector() {
	Locker guard(&mutex);

	if (asIntVector == nullptr) {
		asIntVector = new Vector<int>();

		if (asIntVector == nullptr)
			throw Exception("Failed to allocate Vector<int> in getIntVector()");

		if (asVector == nullptr) {
			asIntVector->add(getInt());
		} else {
			for (int i = 0; i < asVector->size(); i++) {
				ConfigDataItem* curItem = asVector->get(i);

				if (curItem == nullptr)
					continue;

				asIntVector->add(curItem->getInt());
			}
		}
	}

	return *asIntVector;
}

String ConfigDataItem::toString() {
	Locker guard(&mutex);

	usageCounter.increment();

	if (asVector == nullptr)
		return String(asString);

	const Vector<String>& elements = getStringVector();

	StringBuffer buf;

	buf << asString << " = {";

	for (int i = 0; i < elements.size(); ++i) {
		buf << (i == 0 ? " " : ", ") << elements.get(i);
	}

	buf << " }";

	return buf.toString();
}

int ConfigDataItem::getUsageCounter() const {
	return usageCounter;
}

int ConfigDataItem::resetUsageCounter() {
	int prevCount = usageCounter.get(std::memory_order_acquire);
	usageCounter.set(0, std::memory_order_release);

	return prevCount;
}

#ifdef DEBUG_CONFIGMANAGER
void ConfigDataItem::setDebugTag(const String& tag) {
	debugTag = tag;
}
#endif // DEBUG_CONFIGMANAGER
