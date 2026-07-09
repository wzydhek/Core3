#include "SpaceSpawnGroup.h"

SpaceSpawnGroup::SpaceSpawnGroup() {
}

SpaceSpawnGroup::SpaceSpawnGroup(const String& tempName, LuaObject& shipSpawnGroups) {
	templateName = tempName;

	if (!shipSpawnGroups.isValidTable()) {
		return;
	}

	for (int i = 1; i <= shipSpawnGroups.getTableSize(); ++i) {
		lua_rawgeti(shipSpawnGroups.getLuaState(), -1, i);
		LuaObject shipSpawn(shipSpawnGroups.getLuaState());

		if (shipSpawn.isValidTable()) {
			Reference<SpaceSpawn*> spaceSpawn = new SpaceSpawn();
			spaceSpawn->readObject(shipSpawn);

			spawnList.add(spaceSpawn);
		}

		shipSpawn.pop();
	}

	shipSpawnGroups.pop();
}

SpaceSpawnGroup::SpaceSpawnGroup(const SpaceSpawnGroup& gr) : Object() {
	templateName = gr.templateName;
	spawnList = gr.spawnList;
}

SpaceSpawnGroup::~SpaceSpawnGroup() {
}

SpaceSpawnGroup& SpaceSpawnGroup::operator=(const SpaceSpawnGroup& gr) {
	if (this == &gr) {
		return *this;
	}

	templateName = gr.templateName;
	spawnList = gr.spawnList;

	return *this;
}

const String& SpaceSpawnGroup::getTemplateName() const {
	return templateName;
}

const Vector<Reference<SpaceSpawn*>>& SpaceSpawnGroup::getSpawnList() {
	return spawnList;
}

void SpaceSpawnGroup::setTemplateName(const String& templateName) {
	this->templateName = templateName;
}