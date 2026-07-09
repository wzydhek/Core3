#include "SpawnGroup.h"

SpawnGroup::SpawnGroup() {
	minLevelCeiling = 20;
}

SpawnGroup::SpawnGroup(const String& tempName, LuaObject& group) {
	templateName = tempName;
	minLevelCeiling = group.getIntField("minLevelCeiling");

	LuaObject lairSpawns = group.getObjectField("lairSpawns");

	for (int i = 1; i <= lairSpawns.getTableSize(); ++i) {
		lua_rawgeti(lairSpawns.getLuaState(), -1, i);
		LuaObject spawn(lairSpawns.getLuaState());

		if (spawn.isValidTable()) {
			Reference<LairSpawn*> lairSpawn = new LairSpawn();
			lairSpawn->readObject(spawn);

			spawnList.add(lairSpawn);
		}

		spawn.pop();
	}

	lairSpawns.pop();
}

SpawnGroup::SpawnGroup(const SpawnGroup& gr) : Object() {
	templateName = gr.templateName;
	spawnList = gr.spawnList;
	minLevelCeiling = gr.minLevelCeiling;
}

SpawnGroup::~SpawnGroup() {
}

SpawnGroup& SpawnGroup::operator=(const SpawnGroup& gr) {
	if (this == &gr)
		return *this;

	templateName = gr.templateName;
	spawnList = gr.spawnList;
	minLevelCeiling = gr.minLevelCeiling;

	return *this;
}

const String& SpawnGroup::getTemplateName() const {
	return templateName;
}

const Vector<Reference<LairSpawn*>>& SpawnGroup::getSpawnList() {
	return spawnList;
}

void SpawnGroup::setTemplateName(const String& templateName) {
	this->templateName = templateName;
}

int SpawnGroup::getMinLevelCeiling() const {
	return minLevelCeiling;
}