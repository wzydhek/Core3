#include "LairSpawn.h"

LairSpawn::LairSpawn() : Object() {
	spawnLimit = -1;
	minDifficulty = 1;
	maxDifficulty = 1;
	numberToSpawn = 0;
	weighting = 1;
	size = 25;
}

LairSpawn::LairSpawn(const LairSpawn& sp) : Object() {
	spawnLimit = sp.spawnLimit;
	minDifficulty = sp.minDifficulty;
	maxDifficulty = sp.maxDifficulty;
	numberToSpawn = sp.numberToSpawn;
	weighting = sp.weighting;
	size = sp.size;

	lairTemplateName = sp.lairTemplateName;
}

LairSpawn& LairSpawn::operator=(const LairSpawn& sp) {
	if (this == &sp)
		return *this;

	spawnLimit = sp.spawnLimit;
	minDifficulty = sp.minDifficulty;
	maxDifficulty = sp.maxDifficulty;
	numberToSpawn = sp.numberToSpawn;
	weighting = sp.weighting;
	size = sp.size;

	lairTemplateName = sp.lairTemplateName;

	return *this;
}

void LairSpawn::readObject(LuaObject& obj) {
	spawnLimit = obj.getIntField("spawnLimit");
	minDifficulty = obj.getIntField("minDifficulty");
	maxDifficulty = obj.getIntField("maxDifficulty");
	numberToSpawn = obj.getIntField("numberToSpawn");
	weighting = obj.getIntField("weighting");
	size = obj.getFloatField("size");
	lairTemplateName = obj.getStringField("lairTemplateName");
}

int LairSpawn::getSpawnLimit() const {
	return spawnLimit;
}

int LairSpawn::getMinDifficulty() const {
	return minDifficulty;
}

int LairSpawn::getMaxDifficulty() const {
	return maxDifficulty;
}

int LairSpawn::getNumberToSpawn() const {
	return numberToSpawn;
}

int LairSpawn::getWeighting() const {
	return weighting;
}

float LairSpawn::getSize() const {
	return size;
}

const String& LairSpawn::getLairTemplateName() const {
	return lairTemplateName;
}