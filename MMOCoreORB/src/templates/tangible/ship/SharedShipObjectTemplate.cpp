#include "SharedShipObjectTemplate.h"

SharedShipObjectTemplate::SharedShipObjectTemplate() {
}

SharedShipObjectTemplate::~SharedShipObjectTemplate() {
}

const VectorMap<String, float>& SharedShipObjectTemplate::getAttributeMap() const {
	return attributeMap;
}

const VectorMap<String, String>& SharedShipObjectTemplate::getComponentNames() const {
	return componentNames;
}

const VectorMap<String, VectorMap<String, float>>& SharedShipObjectTemplate::getComponentValues() const {
	return componentValues;
}

const VectorMap<String, Vector<Vector3>>& SharedShipObjectTemplate::getSparkLocations() {
	return sparkLocations;
}

const VectorMap<String, Vector<Vector3>>& SharedShipObjectTemplate::getLaunchLocations() {
	return launchLocations;
}

const VectorMap<int, uint32>& SharedShipObjectTemplate::getPlasmaConduitTypes() {
	return plasmaConduitTypes;
}

void SharedShipObjectTemplate::readAttributeMap(LuaObject* templateData) {
	auto attributes = templateData->getObjectField("attributes");

	if (attributes.isValidTable()) {
		for (int i = 1; i <= attributes.getTableSize(); ++i) {
			auto entry = attributes.getObjectAt(i);

			if (entry.isValidTable() && entry.getTableSize() == 2) {
				String key = entry.getStringAt(1);
				float value = entry.getFloatAt(2);
				attributeMap.put(key, value);
			}

			entry.pop();
		}
	}

	attributes.pop();
}

void SharedShipObjectTemplate::readPobData(LuaObject* templateData) {
	// damage spark locations
	auto sparkLocs = templateData->getObjectField("sparkLocations");

	if (sparkLocs.isValidTable()) {
		for (int i = 1; i <= sparkLocs.getTableSize(); ++i) {
			auto cellTable = sparkLocs.getObjectAt(i);

			if (cellTable.isValidTable()) {
				String cellName = cellTable.getStringField("cellName");
				Vector<Vector3> locations;

				for (int k = 2; k <= cellTable.getTableSize(); ++k) {
					auto coordinates = cellTable.getObjectAt(k);

					if (coordinates.isValidTable()) {
						Vector3 location;

						location.setX(coordinates.getFloatField("x"));
						location.setZ(coordinates.getFloatField("z"));
						location.setY(coordinates.getFloatField("y"));

						locations.add(location);
					}
					coordinates.pop();
				}

				sparkLocations.put(cellName, locations);
			}
			cellTable.pop();
		}
	}
	sparkLocs.pop();

	// player launch locations
	auto launchLoc = templateData->getObjectField("launchPoints");

	if (launchLoc.isValidTable()) {
		for (int i = 1; i <= launchLoc.getTableSize(); ++i) {
			auto cellTable = launchLoc.getObjectAt(i);

			if (cellTable.isValidTable()) {
				String cellName = cellTable.getStringField("cellName");
				Vector<Vector3> locations;

				for (int k = 1; k <= cellTable.getTableSize(); ++k) {
					auto coordinates = cellTable.getObjectAt(k);

					if (coordinates.isValidTable()) {
						Vector3 location;

						location.setX(coordinates.getFloatField("x"));
						location.setZ(coordinates.getFloatField("z"));
						location.setY(coordinates.getFloatField("y"));

						locations.add(location);
					}
					coordinates.pop();
				}

				launchLocations.put(cellName, locations);
			}
			cellTable.pop();
		}
	}
	launchLoc.pop();

	// Plasma Conduits
	auto plasmaConduits = templateData->getObjectField("plasmaConduits");

	if (plasmaConduits.isValidTable()) {
		for (int i = 1; i <= plasmaConduits.getTableSize(); ++i) {
			auto conduitTable = plasmaConduits.getObjectAt(i);

			if (conduitTable.isValidTable()) {
				// Get information for child object
				String templateFile = conduitTable.getStringField("templateFile");

				Vector3 position;
				position.setX(conduitTable.getFloatField("x"));
				position.setZ(conduitTable.getFloatField("z"));
				position.setY(conduitTable.getFloatField("y"));

				Quaternion direction;
				direction.set(conduitTable.getFloatField("ow"), conduitTable.getFloatField("ox"), conduitTable.getFloatField("oy"), conduitTable.getFloatField("oz"));

				int cellid = conduitTable.getIntField("cellid");
				int containmentType = conduitTable.getIntField("containmentType");
				int componentSlot = (int)conduitTable.getFloatField("componentSlot", -2.f);

				ChildObject object(position, direction, templateFile, cellid, containmentType, componentSlot);

				// Add conduit as child object so it is created
				childObjects.add(object);

				// Load the component type
				plasmaConduitTypes.put(i, conduitTable.getIntField("componentDamageSlot"));

				conduitTable.pop();
			}
		}
	}
	plasmaConduits.pop();
}

void SharedShipObjectTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
	// if (!templateData->isValidTable())
	// return;

	chassisDataName = templateData->getStringField("name");
	chassisTypeName = templateData->getStringField("type");

	chassisCategory = templateData->getStringField("category");
	chassisLevel = templateData->getIntField("level");

	if (chassisTypeName == "") {
		chassisTypeName = chassisDataName;
	}

	chassisHitpoints = templateData->getFloatField("chassisHitpoints", 100.f);
	chassisSlipRate = templateData->getFloatField("slideFactor", 1.75f);
	chassisSpeed = templateData->getFloatField("chassisSpeed", 1.f);
	chassisMass = templateData->getFloatField("chassisMass", 10000.f);

	shipDifficulty = templateData->getStringField("difficulty");
	shipFaction = templateData->getStringField("faction");

	readAttributeMap(templateData);

	// SceneObjectType::POBSHIP
	if (gameObjectType == 536870917) {
		readPobData(templateData);
	}

	try {
		for (int slot = 0; slot <= Components::CAPITALSLOTMAX; ++slot) {
			String key = Components::shipComponentSlotToString(slot);
			LuaObject component = templateData->getObjectField(key);

			if (!component.isValidTable()) {
				component.pop();
				continue;
			}

			String name = component.getStringField("name", "");
			VectorMap<String, float> map;
			map.setNullValue(0.f);

			switch (slot) {
				case Components::REACTOR: {
					const char* fields[] = {"hitpoints", "armor"};
					loadMap(fields, 2, map, component);
					break;
				}

				case Components::ENGINE: {
					const char* fields[] = {"hitpoints", "armor", "speed", "pitch", "roll", "yaw", "acceleration", "deceleration", "pitchRate", "rollRate", "yawRate"};
					loadMap(fields, 11, map, component);
					break;
				}

				case Components::SHIELD0: {
					const char* fields[] = {"hitpoints", "armor", "front", "back", "regen"};
					loadMap(fields, 5, map, component);
					break;
				}

				case Components::SHIELD1: {
					const char* fields[] = {"hitpoints", "armor", "front", "back", "regen"};
					loadMap(fields, 5, map, component);
					break;
				}

				case Components::ARMOR0: {
					const char* fields[] = {"hitpoints", "armor"};
					loadMap(fields, 2, map, component);
					break;
				}

				case Components::ARMOR1: {
					const char* fields[] = {"hitpoints", "armor"};
					loadMap(fields, 2, map, component);
					break;
				}

				case Components::CAPACITOR: {
					const char* fields[] = {"hitpoints", "armor", "rechargeRate", "energy"};
					loadMap(fields, 4, map, component);
					break;
				}

				case Components::BOOSTER: {
					const char* fields[] = {"hitpoints", "armor", "energy", "acceleration", "speed", "energyUsage", "rechargeRate"};
					loadMap(fields, 7, map, component);
					break;
				}

				case Components::DROID_INTERFACE: {
					const char* fields[] = {"hitpoints", "armor"};
					loadMap(fields, 2, map, component);
					break;
				}

				case Components::BRIDGE: {
					const char* fields[] = {"hitpoints", "armor"};
					loadMap(fields, 2, map, component);
					break;
				}

				case Components::HANGAR: {
					const char* fields[] = {"hitpoints", "armor"};
					loadMap(fields, 2, map, component);
					break;
				}

				case Components::TARGETING_STATION: {
					const char* fields[] = {"hitpoints", "armor"};
					loadMap(fields, 2, map, component);
					break;
				}

				default: {
					if (slot >= Components::WEAPON_START) {
						const char* fields[] = {"hitpoints", "armor", "rate", "drain", "maxDamage", "minDamage", "shieldEfficiency", "armorEfficiency", "ammo", "ammo_type"};
						loadMap(fields, 10, map, component);
					}

					break;
				}
			};

			componentNames.put(key, name);
			componentValues.put(key, map);

			component.pop();
		}
	} catch (Exception& e) {
		e.printStackTrace();
	}
}

const String& SharedShipObjectTemplate::getShipName() const {
	return chassisDataName.get();
}

const String& SharedShipObjectTemplate::getShipType() const {
	return chassisTypeName.get();
}

float SharedShipObjectTemplate::getChassisHitpoints() const {
	return chassisHitpoints;
}

float SharedShipObjectTemplate::getChassisSlipRate() const {
	return chassisSlipRate;
}

float SharedShipObjectTemplate::getChassisSpeed() const {
	return chassisSpeed;
}

float SharedShipObjectTemplate::getChassisMass() const {
	return chassisMass;
}

bool SharedShipObjectTemplate::shipHasWings() const {
	return hasWings;
}

const String& SharedShipObjectTemplate::getShipDifficulty() const {
	return shipDifficulty.get();
}

const String& SharedShipObjectTemplate::getShipFaction() const {
	return shipFaction.get();
}

const String& SharedShipObjectTemplate::getChassisCategory() const {
	return chassisCategory.get();
}

int SharedShipObjectTemplate::getChassisLevel() const {
	return chassisLevel.get();
}

void SharedShipObjectTemplate::parseVariableData(const String& varName, Chunk* data) {
	if (varName == "interiorLayoutFileName") {
		interiorLayoutFileName.parse(data);
	} else if (varName == "cockpitFilename") {
		cockpitFilename.parse(data);
	} else if (varName == "hasWings") {
		hasWings.parse(data);
	} else if (varName == "playerControlled") {
		playerControlled.parse(data);
	}
}

void SharedShipObjectTemplate::loadMap(const char** fields, int fieldsLen, VectorMap<String, float>& map, LuaObject& obj) {
	for (int i = 0; i < fieldsLen; i++) {
		map.put(fields[i], obj.getFloatField(fields[i]));
	}
}

void SharedShipObjectTemplate::parseFileData(IffStream* iffStream) {
	iffStream->openChunk('PCNT');

	int variableCount = iffStream->getInt();

	iffStream->closeChunk('PCNT');

	for (int i = 0; i < variableCount; ++i) {
		// while (iffStream->getRemainingSubChunksNumber() > 0) {
		Chunk* chunk = iffStream->openChunk('XXXX');

		if (chunk == nullptr)
			continue;

		String varName;

		iffStream->getString(varName);

		// std::cout << "parsing wtf shit:[" << varName.toStdString() << "]\n";
		parseVariableData(varName, chunk);

		iffStream->closeChunk();
	}
}

void SharedShipObjectTemplate::readObject(IffStream* iffStream) {
	uint32 nextType = iffStream->getNextFormType();

	if (nextType != 'SSHP') {
		// Logger::console.error("expecting SHOT got " + String::hexvalueOf((int)nextType));

		SharedTangibleObjectTemplate::readObject(iffStream);

		return;
	}

	iffStream->openForm('SSHP');

	uint32 derv = iffStream->getNextFormType();

	if (derv == 'DERV') {
		loadDerv(iffStream);

		derv = iffStream->getNextFormType();
	}

	iffStream->openForm(derv);

	try {
		parseFileData(iffStream);
	} catch (Exception& e) {
		String msg;
		msg += "exception caught parsing file data ->";
		msg += e.getMessage();

		Logger::console.error(msg);
	}

	iffStream->closeForm(derv);

	if (iffStream->getRemainingSubChunksNumber() > 0) {
		readObject(iffStream);
	}

	iffStream->closeForm('SSHP');
}