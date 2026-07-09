/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

// #define DEBUG_CONFIGMANAGER

#include "engine/engine.h"

namespace conf {

	class ConfigDataItem {
		bool asBool;
		String asString;
		lua_Number asNumber;
		Vector <ConfigDataItem *>* asVector = nullptr;
		Vector <String>* asStringVector = nullptr;
		SortedVector <String>* asSortedStringVector = nullptr;
		Vector <int>* asIntVector = nullptr;
		mutable AtomicInteger usageCounter = 0;

		Mutex mutex;

	public:
		ConfigDataItem(lua_Number value);
		ConfigDataItem(int value);
		ConfigDataItem(bool value);
		ConfigDataItem(float value);
		ConfigDataItem(const String& value);
		ConfigDataItem(Vector <ConfigDataItem *>* value);

		~ConfigDataItem();

		bool getBool() const;

		float getFloat() const;

		int getInt() const;

		const String& getString() const;

		const Vector<String>& getStringVector();

		const SortedVector<String>& getSortedStringVector();

		const Vector<int>& getIntVector();

		void getAsJSON(JSONSerializationType& jsonData);

		String toString();

		int getUsageCounter() const;

		int resetUsageCounter();

#ifdef DEBUG_CONFIGMANAGER
	private:
		String debugTag;

	public:
		void setDebugTag(const String& tag);
#endif // DEBUG_CONFIGMANAGER
	};

	class ConfigManager : public Singleton<ConfigManager>, public Object, public Logger {
	protected:
		Lua lua;

		Timer configStartTime;
		bool logChanges = false;

		VectorMap<String, ConfigDataItem *> configData;

		// Each change increments configVersion allowing cached results to auto-reload
		mutable AtomicInteger configVersion = 0;

		ReadWriteLock mutex;

	private:
		ConfigDataItem* findItem(const String& name, unsigned int accountID = 0) const;
		bool updateItem(const String& name, ConfigDataItem* newItem);

		bool parseConfigData(const String& prefix, bool isGlobal = false, int maxDepth = 5);
		bool parseConfigJSONRecursive(const String prefix, JSONSerializationType jsonNode, String& errorMessage, bool updateOnly = true);
		void writeJSONPath(StringTokenizer& tokens, JSONSerializationType& jsonData, const JSONSerializationType& jsonValue);
		bool isSensitiveKey(const String& key);

		void incrementConfigVersion();

		String withAccount(const String& name, unsigned int accountID) const;

	public:
		ConfigManager();
		~ConfigManager();

		bool loadConfigData();
		void clearConfigData();
		void cacheHotItems();
		bool parseConfigJSON(const String& jsonString, String& errorMessage, bool updateOnly = true);
		bool parseConfigJSON(const JSONSerializationType jsonData, String& errorMessage, bool updateOnly = true);
		void dumpConfig(bool includeSecure = false);
		bool testConfig(ConfigManager* configManager);

		uint64 getConfigDataAgeMs() const;

		int getConfigVersion();

		// General config functions
		bool contains(const String& name, unsigned int accountID = 0) const;
		int getUsageCounter(const String& name) const;
		int getInt(const String& name, int defaultValue, unsigned int accountID = 0);
		bool getBool(const String& name, bool defaultValue, unsigned int accountID = 0);
		float getFloat(const String& name, float defaultValue, unsigned int accountID = 0);
		const String& getString(const String& name, const String& defaultValue, unsigned int accountID = 0);
		const Vector<String>& getStringVector(const String& name, unsigned int accountID = 0);
		const SortedVector<String>& getSortedStringVector(const String& name, unsigned int accountID = 0);
		const Vector<int>& getIntVector(const String& name, unsigned int accountID = 0);
		bool getAsJSON(const String& target, JSONSerializationType& jsonData);

		Logger::LogLevel getLogLevel(const String& name, Logger::LogLevel defaultValue, unsigned int accountID = 0);

		bool setNumber(const String& name, lua_Number newValue);
		bool setInt(const String& name, int newValue);
		bool setBool(const String& name, bool newValue);
		bool setFloat(const String& name, float newValue);
		bool setString(const String& name, const String& newValue);
		bool setStringFromFile(const String& name, const String& fileName);

		// Legacy getters
		bool getMakeLogin();

		bool getMakeZone();

		bool getMakePing();

		bool getMakeStatus();

		bool getDumpObjFiles();

		bool shouldUnloadContainers();

		bool shouldUseMetrics();

		bool getPvpMode();

		bool setPvpMode(bool val);

		const String& getORBNamingDirectoryAddress();

		uint16 getORBNamingDirectoryPort();

		const String& getDBHost();

		bool isProgressMonitorActivated();

		bool includeFactionPetsForMissionDifficulty();

		int getDBPort();

		const String& getDBName();

		const String& getDBUser();

		const String& getDBPass();

		const String& getDBSecret();

		const String& getMantisHost();

		int getMantisPort();

		const String& getLatestTre();

		const Vector<String>& getTreFiles();

		const String& getMantisName();

		const String& getMantisUser();

		const String& getMantisPass();

		const String& getMantisPrefix();

		const String& getMessageOfTheDay();

		const String& getRevision();

		const String& getMetricsHost();

		const String& getMetricsPrefix();

		int getMetricsPort();

		const String& getTrePath();

		uint16 getLoginPort();

		uint16 getStatusPort();

		uint16 getPingPort();

		const String& getLoginRequiredVersion();

		int getLoginProcessingThreads();

		int getLoginAllowedConnections();

		int getStatusAllowedConnections();

		int getPingAllowedConnections();

		int getStatusInterval();

		int getAutoReg();

		int getZoneProcessingThreads();

		int getZoneAllowedConnections();

		int getZoneGalaxyID();

		int getZoneServerPort();

		const SortedVector<String>& getEnabledZones();

		const SortedVector<String>& getEnabledSpaceZones();

		int getPurgeDeletedCharacters();

		int getMaxNavMeshJobs();

		int getMaxAuctionSearchJobs();

		const String& getLogFile();

		int getLogFileLevel();

		int getRotateLogSizeMB();

		bool getRotateLogAtStart();

		void setProgressMonitors(bool val);

		const String& getTermsOfService();

		int getTermsOfServiceVersion();

		bool getJsonLogOutput();

		bool getSyncLogOutput();

		bool getLuaLogJSON();

		bool getPathfinderLogJSON();

		int getCleanupMailCount();

		int getRESTPort();

		const String& getInactiveAccountTitle();

		const String& getInactiveAccountText();

		bool getCharacterBuilderEnabled();

		int getPlayerLogLevel();

		int getMaxLogLines();

		int getSessionStatsSeconds();

		int getOnlineLogSeconds();

		int getOnlineLogSize();

		String getNoTradeMessage();

		String getForceNoTradeMessage();

		String getForceNoTradeADKMessage();

		uint32 getAiAgentConsoleThrottle();

#ifdef DEBUG_AI
		bool getAiAgentLoadTesting();
#endif // DEBUG_AI

		bool isPvpBroadcastChannelEnabled();

		bool useCovertOvertSystem();

		bool getLoginEnableSessionId();

		int getMinLairSpawnInterval();

		int getMinSpaceSpawnInterval();

		bool disableWorldSpawns();

		bool disableSpaceSpawns();

		float getSpawnCheckRange();

		float getSpaceSpawnCheckRange();

		bool getLootDebugAttributes();


		/*

			JTL Configs

		*/


		bool isJtlEnabled();

		bool launchFromDevice();
	};
}

using namespace conf;
