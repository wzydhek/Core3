#include "LairTemplate.h"

LairTemplate::LairTemplate(const String& templateName) {
	spawnLimit = 0;
	buildings.setAllowDuplicateInsertPlan();
	buildings.setNullValue(nullptr);
	faction = 0;
	mobType = CREATURE;
	buildingType = LAIR;

	name = templateName;
}

LairTemplate::~LairTemplate() {
}

String LairTemplate::getBuilding(uint32 difficulty) const {
	if (buildingType == NONE)
		return String();

	const Vector<String>* objects = nullptr;

	objects = buildings.get(difficulty);

	if (objects == nullptr) {
		for (int i = 0; i < buildings.size() && objects == nullptr; ++i) {
			objects = buildings.elementAt(i).getValue();
		}
	}

	if (objects != nullptr && objects->size() > 0)
		return objects->get(System::random(objects->size() - 1));
	else
		return String();
}

String LairTemplate::getMissionBuilding(uint32 difficulty) const {
	if (!missionBuilding.isEmpty() || difficulty > VERYHARD)
		return missionBuilding;

	return getBuilding(difficulty);
}

const Vector<String>* LairTemplate::getBuildings(int difficulty) const {
	return buildings.get((uint32)difficulty);
}

void LairTemplate::readObject(LuaObject* templateData) {
	spawnLimit = templateData->getIntField("spawnLimit");

	if (templateData->getStringField("faction").length() > 0) {
		String factionString = templateData->getStringField("faction");

		if (factionString == "imperial") {
			faction = Factions::FACTIONIMPERIAL;
		} else if (factionString == "rebel") {
			faction = Factions::FACTIONREBEL;
		}
	}

	if (templateData->getStringField("mobType").length() > 0) {
		if (templateData->getStringField("mobType") == "npc")
			mobType = NPC;
	}

	if (templateData->getStringField("buildingType").length() > 0) {
		if (templateData->getStringField("buildingType") == "theater")
			buildingType = THEATER;
		else if (templateData->getStringField("buildingType") == "none")
			buildingType = NONE;
	}

	LuaObject mobs = templateData->getObjectField("mobiles");

	for (int i = 1; i <= mobs.getTableSize(); ++i) {
		lua_rawgeti(mobs.getLuaState(), -1, i);
		LuaObject mobile(mobs.getLuaState());

		if (mobile.isValidTable()) {
			String mob = mobile.getStringAt(1);
			int weight = (int)mobile.getIntAt(2);

			mobiles.put(mob, weight);

			for (int j = 0; j < weight; ++j) {
				weightedMobiles.add(mob);
			}
		}

		mobile.pop();
	}

	mobs.pop();

	LuaObject bossMobs = templateData->getObjectField("bossMobiles");

	for (int i = 1; i <= bossMobs.getTableSize(); ++i) {
		lua_rawgeti(bossMobs.getLuaState(), -1, i);
		LuaObject bossMobile(bossMobs.getLuaState());

		if (bossMobile.isValidTable()) {
			String bossMob = bossMobile.getStringAt(1);
			int number = (int)bossMobile.getIntAt(2);

			bossMobiles.put(bossMob, number);
		}

		bossMobile.pop();
	}

	bossMobs.pop();

	LuaObject veryEasy = templateData->getObjectField("buildingsVeryEasy");
	Vector<String>* buildings = this->buildings.get((uint32)VERYEASY);

	if (buildings == nullptr) {
		buildings = new Vector<String>();
		this->buildings.put(VERYEASY, buildings);
	}

	for (int i = 1; i <= veryEasy.getTableSize(); ++i) {
		buildings->add(veryEasy.getStringAt(i));
	}

	veryEasy.pop();

	LuaObject easy = templateData->getObjectField("buildingsEasy");
	buildings = this->buildings.get((uint32)EASY);

	if (buildings == nullptr) {
		buildings = new Vector<String>();
		this->buildings.put(EASY, buildings);
	}

	for (int i = 1; i <= easy.getTableSize(); ++i) {
		buildings->add(easy.getStringAt(i));
	}

	easy.pop();

	LuaObject medium = templateData->getObjectField("buildingsMedium");

	buildings = this->buildings.get((uint32)MEDIUM);

	if (buildings == nullptr) {
		buildings = new Vector<String>();
		this->buildings.put(MEDIUM, buildings);
	}

	for (int i = 1; i <= medium.getTableSize(); ++i) {
		buildings->add(medium.getStringAt(i));
	}

	medium.pop();

	LuaObject hard = templateData->getObjectField("buildingsHard");

	buildings = this->buildings.get((uint32)HARD);

	if (buildings == nullptr) {
		buildings = new Vector<String>();
		this->buildings.put(HARD, buildings);
	}

	for (int i = 1; i <= hard.getTableSize(); ++i) {
		buildings->add(hard.getStringAt(i));
	}

	hard.pop();

	LuaObject veryHard = templateData->getObjectField("buildingsVeryHard");

	buildings = this->buildings.get((uint32)VERYHARD);

	if (buildings == nullptr) {
		buildings = new Vector<String>();
		this->buildings.put((uint32)VERYHARD, buildings);
	}

	for (int i = 1; i <= veryHard.getTableSize(); ++i) {
		buildings->add(veryHard.getStringAt(i));
	}

	veryHard.pop();

	if (templateData->getStringField("missionBuilding").length() > 0) {
		missionBuilding = templateData->getStringField("missionBuilding");
	}
}

int LairTemplate::getSpawnLimit() const {
	return spawnLimit;
}

const VectorMap<String, int>* LairTemplate::getMobiles() const {
	return &mobiles;
}

const Vector<String>* LairTemplate::getWeightedMobiles() const {
	return &weightedMobiles;
}

const VectorMap<String, int>* LairTemplate::getBossMobiles() const {
	return &bossMobiles;
}

bool LairTemplate::hasBossMobs() const {
	return bossMobiles.size() > 0;
}

bool LairTemplate::isLairTemplate() {
	return true;
}

const String& LairTemplate::getName() const {
	return name;
}

unsigned int LairTemplate::getFaction() const {
	return faction;
}

LairTemplate::MobType LairTemplate::getMobType() const {
	return mobType;
}

LairTemplate::BuildingType LairTemplate::getBuildingType() const {
	return buildingType;
}