#include "CrystalData.h"

CrystalData::CrystalData() : Object(), minDamage(0), maxDamage(0), minHitpoints(0), maxHitpoints(0), minHealthSac(0), maxHealthSac(0), minActionSac(0), maxActionSac(0), minMindSac(0), maxMindSac(0), minAttackSpeed(0.0), maxAttackSpeed(0.0), minForceCost(0.0), maxForceCost(0.0), minWoundChance(0), maxWoundChance(0) {
}

CrystalData::CrystalData(const CrystalData& data) : Object() {
	minDamage = data.minDamage;
	maxDamage = data.maxDamage;
	minHitpoints = data.minHitpoints;
	maxHitpoints = data.maxHitpoints;
	minHealthSac = data.minHealthSac;
	maxHealthSac = data.maxHealthSac;
	minActionSac = data.minActionSac;
	maxActionSac = data.maxActionSac;
	minMindSac = data.minMindSac;
	maxMindSac = data.maxMindSac;
	minAttackSpeed = data.minAttackSpeed;
	maxAttackSpeed = data.maxAttackSpeed;
	minForceCost = data.minForceCost;
	maxForceCost = data.maxForceCost;
	minWoundChance = data.minWoundChance;
	maxWoundChance = data.maxWoundChance;
}

CrystalData& CrystalData::operator=(const CrystalData& data) {
	if (this == &data)
		return *this;

	minDamage = data.minDamage;
	maxDamage = data.maxDamage;
	minHitpoints = data.minHitpoints;
	maxHitpoints = data.maxHitpoints;
	minHealthSac = data.minHealthSac;
	maxHealthSac = data.maxHealthSac;
	minActionSac = data.minActionSac;
	maxActionSac = data.maxActionSac;
	minMindSac = data.minMindSac;
	maxMindSac = data.maxMindSac;
	minAttackSpeed = data.minAttackSpeed;
	maxAttackSpeed = data.maxAttackSpeed;
	minForceCost = data.minForceCost;
	maxForceCost = data.maxForceCost;
	minWoundChance = data.minWoundChance;
	maxWoundChance = data.maxWoundChance;

	return *this;
}

void CrystalData::readObject(LuaObject* luaObject) {
	minDamage = luaObject->getIntField("minDamage");
	maxDamage = luaObject->getIntField("maxDamage");
	minHitpoints = luaObject->getIntField("minHitpoints");
	maxHitpoints = luaObject->getIntField("maxHitpoints");
	minHealthSac = luaObject->getIntField("minHealthSac");
	maxHealthSac = luaObject->getIntField("maxHealthSac");
	minActionSac = luaObject->getIntField("minActionSac");
	maxActionSac = luaObject->getIntField("maxActionSac");
	minMindSac = luaObject->getIntField("minMindSac");
	maxMindSac = luaObject->getIntField("maxMindSac");
	minAttackSpeed = luaObject->getFloatField("minAttackSpeed");
	maxAttackSpeed = luaObject->getFloatField("maxAttackSpeed");
	minForceCost = luaObject->getFloatField("minForceCost");
	maxForceCost = luaObject->getFloatField("maxForceCost");
	minWoundChance = luaObject->getIntField("minWoundChance");
	maxWoundChance = luaObject->getIntField("maxWoundChance");
}

int CrystalData::getMinDamage() const {
	return minDamage;
}

int CrystalData::getMaxDamage() const {
	return maxDamage;
}

int CrystalData::getMinHitpoints() const {
	return minHitpoints;
}

int CrystalData::getMaxHitpoints() const {
	return maxHitpoints;
}

int CrystalData::getMinHealthSac() const {
	return minHealthSac;
}

int CrystalData::getMaxHealthSac() const {
	return maxHealthSac;
}

int CrystalData::getMinActionSac() const {
	return minActionSac;
}

int CrystalData::getMaxActionSac() const {
	return maxActionSac;
}

int CrystalData::getMinMindSac() const {
	return minMindSac;
}

int CrystalData::getMaxMindSac() const {
	return maxMindSac;
}

int CrystalData::getMinWoundChance() const {
	return minWoundChance;
}

float CrystalData::getMinAttackSpeed() const {
	return minAttackSpeed;
}

float CrystalData::getMaxAttackSpeed() const {
	return maxAttackSpeed;
}

float CrystalData::getMinForceCost() const {
	return minForceCost;
}

float CrystalData::getMaxForceCost() const {
	return maxForceCost;
}

int CrystalData::getMaxWoundChance() const {
	return maxWoundChance;
}