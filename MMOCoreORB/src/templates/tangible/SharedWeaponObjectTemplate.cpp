/*
 * SharedWeaponObjectTemplate.cpp
 *
 *  Created on: 05/05/2010
 *      Author: victor
 */

#include "SharedWeaponObjectTemplate.h"

SharedWeaponObjectTemplate::SharedWeaponObjectTemplate() {
	damageType = 0;

	armorPiercing = 0;

	healthAttackCost = 0;
	actionAttackCost = 0;
	mindAttackCost = 0;
	forceCost = 0.0;

	pointBlankAccuracy = 0;
	pointBlankRange = 0;

	idealRange = 0;
	idealAccuracy = 0;

	maxRange = 0;
	maxRangeAccuracy = 0;

	minDamage = 0;
	maxDamage = 0;

	woundsRatio = 0;

	area = 0;

	attackSpeed = 0;

	weaponType = 0xFFFFFFFF;
}

SharedWeaponObjectTemplate::~SharedWeaponObjectTemplate() {
}

void SharedWeaponObjectTemplate::parseVariableData(const String& varName, LuaObject* templateData) {
	lua_State* state = templateData->getLuaState();

	if (varName == "weaponEffect") {
		weaponEffect = Lua::getStringParameter(state);
	} else if (varName == "weaponEffectIndex") {
		weaponEffectIndex = Lua::getIntParameter(state);
	} else if (varName == "attackType") {
		attackType = Lua::getIntParameter(state);
	} else if (varName == "weaponType") {
		weaponType = Lua::getIntParameter(state);
	} else
		templateData->pop();
}

void SharedWeaponObjectTemplate::parseVariableData(const String& varName, Chunk* data) {
	if (varName == "weaponEffect") {
		weaponEffect.parse(data);
	} else if (varName == "weaponEffectIndex") {
		weaponEffectIndex.parse(data);
	} else if (varName == "attackType") {
		attackType.parse(data);
	}
}

void SharedWeaponObjectTemplate::parseFileData(IffStream* iffStream) {
	iffStream->openChunk('PCNT');

	int variableCount = iffStream->getInt();

	iffStream->closeChunk('PCNT');

	for (int i = 0; i < variableCount; ++i) {
	//while (iffStream->getRemainingSubChunksNumber() > 0) {
		Chunk* chunk = iffStream->openChunk('XXXX');

		if (chunk == nullptr)
			continue;

		String varName;
		iffStream->getString(varName);

		//std::cout << "parsing wtf shit:[" << varName.toStdString() << "]\n";
		parseVariableData(varName, chunk);

		iffStream->closeChunk();
	}
}

void SharedWeaponObjectTemplate::readObject(IffStream* iffStream) {
	uint32 nextType = iffStream->getNextFormType();

	if (nextType != 'SWOT') {
		//Logger::console.error("expecting SHOT got " + String::hexvalueOf((int)nextType));

		SharedTangibleObjectTemplate::readObject(iffStream);

		return;
	}

	iffStream->openForm('SWOT');

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

	iffStream->closeForm('SWOT');
}

void SharedWeaponObjectTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	lua_State* L = templateData->getLuaState();

	if (!templateData->isValidTable())
		return;

	int i = 0;

	lua_pushnil(L);  
	while (lua_next(L, -2) != 0) {
		// 'key' is at index -2 and 'value' at index -1 
		//printf("%s - %s\n",
		//		lua_tostring(L, -2), lua_typename(L, lua_type(L, -1)));

		int type = lua_type(L, -2);

		if (type == LUA_TSTRING) {
			size_t len = 0;
			const char* varName = lua_tolstring(L, -2, &len);

			parseVariableData(varName, templateData);
		} else
			lua_pop(L, 1);
		
		++i;
	}

	//here goes server data only

	xpType = templateData->getStringField("xpType");

	damageType = templateData->getIntField("damageType");

	LuaObject certifications = templateData->getObjectField("certificationsRequired");

	certificationsRequired.removeAll();

	for (int i = 1; i <= certifications.getTableSize(); ++i) {
		certificationsRequired.add(certifications.getStringAt(i));
	}

	certifications.pop();

	creatureAccuracyModifiers.removeAll();

	LuaObject accMods = templateData->getObjectField("creatureAccuracyModifiers");

	for (int i = 1; i <= accMods.getTableSize(); ++i) {
		creatureAccuracyModifiers.add(accMods.getStringAt(i));
	}

	accMods.pop();

	creatureAimModifiers.removeAll();

	LuaObject aimMods = templateData->getObjectField("creatureAimModifiers");

	for (int i = 1; i <= aimMods.getTableSize(); ++i) {
		creatureAimModifiers.add(aimMods.getStringAt(i));
	}

	aimMods.pop();

	defenderDefenseModifiers.removeAll();

	LuaObject defMods = templateData->getObjectField("defenderDefenseModifiers");

	for (int i = 1; i <= defMods.getTableSize(); ++i) {
		defenderDefenseModifiers.add(defMods.getStringAt(i));
	}

	defMods.pop();

	damageModifiers.removeAll();

	LuaObject dmgMods = templateData->getObjectField("damageModifiers");

	for (int i = 1; i <= dmgMods.getTableSize(); ++i) {
		damageModifiers.add(dmgMods.getStringAt(i));
	}

	dmgMods.pop();

	speedModifiers.removeAll();

	LuaObject speedMods = templateData->getObjectField("speedModifiers");

	for (int i = 1; i <= speedMods.getTableSize(); ++i) {
		speedModifiers.add(speedMods.getStringAt(i));
	}

	speedMods.pop();

	defenderSecondaryDefenseModifiers.removeAll();

	LuaObject secMods = templateData->getObjectField("defenderSecondaryDefenseModifiers");

	for (int i = 1; i <= secMods.getTableSize(); ++i)
		defenderSecondaryDefenseModifiers.add(secMods.getStringAt(i));

	secMods.pop();

	defenderToughnessModifiers.removeAll();

	LuaObject toughMods = templateData->getObjectField("defenderToughnessModifiers");

	for (int i = 1; i <= toughMods.getTableSize(); ++i)
		defenderToughnessModifiers.add(toughMods.getStringAt(i));

	toughMods.pop();

	armorPiercing = templateData->getIntField("armorPiercing");

	healthAttackCost = templateData->getIntField("healthAttackCost");
	actionAttackCost = templateData->getIntField("actionAttackCost");
	mindAttackCost = templateData->getIntField("mindAttackCost");
	forceCost = templateData->getFloatField("forceCost");

	pointBlankAccuracy = templateData->getIntField("pointBlankAccuracy");
	pointBlankRange = templateData->getIntField("pointBlankRange");

	idealRange = templateData->getIntField("idealRange");
	idealAccuracy = templateData->getIntField("idealAccuracy");

	maxRange = templateData->getIntField("maxRange");
	maxRangeAccuracy = templateData->getIntField("maxRangeAccuracy");

	minDamage = templateData->getIntField("minDamage");
	maxDamage = templateData->getIntField("maxDamage");

	woundsRatio = templateData->getFloatField("woundsRatio");

	area = templateData->getIntField("area");

	attackSpeed = templateData->getFloatField("attackSpeed");

	combatSpam = templateData->getStringField("combatSpam");
	animationType = templateData->getStringField("animationType");
}

String SharedWeaponObjectTemplate::getXpType() const {
	return xpType;
}

int SharedWeaponObjectTemplate::getActionAttackCost() const {
	return actionAttackCost;
}

int SharedWeaponObjectTemplate::getArea() const {
	return area;
}

int SharedWeaponObjectTemplate::getArmorPiercing() const {
	return armorPiercing;
}

float SharedWeaponObjectTemplate::getAttackSpeed() const {
	return attackSpeed;
}

float SharedWeaponObjectTemplate::getForceCost() const {
	return forceCost;
}

int SharedWeaponObjectTemplate::getHealthAttackCost() const {
	return healthAttackCost;
}

int SharedWeaponObjectTemplate::getIdealAccuracy() const {
	return idealAccuracy;
}

int SharedWeaponObjectTemplate::getIdealRange() const {
	return idealRange;
}

int SharedWeaponObjectTemplate::getMaxDamage() const {
	return maxDamage;
}

int SharedWeaponObjectTemplate::getMaxRange() const {
	return maxRange;
}

int SharedWeaponObjectTemplate::getMaxRangeAccuracy() const {
	return maxRangeAccuracy;
}

int SharedWeaponObjectTemplate::getMinDamage() const {
	return minDamage;
}

int SharedWeaponObjectTemplate::getMindAttackCost() const {
	return mindAttackCost;
}

int SharedWeaponObjectTemplate::getPointBlankAccuracy() const {
	return pointBlankAccuracy;
}

int SharedWeaponObjectTemplate::getPointBlankRange() const {
	return pointBlankRange;
}

float SharedWeaponObjectTemplate::getWoundsRatio() const {
	return woundsRatio;
}

void SharedWeaponObjectTemplate::setActionAttackCost(int actionAttackCost) {
	this->actionAttackCost = actionAttackCost;
}

void SharedWeaponObjectTemplate::setArea(int area) {
	this->area = area;
}

void SharedWeaponObjectTemplate::setArmorPiercing(int armorPiercing) {
	this->armorPiercing = armorPiercing;
}

void SharedWeaponObjectTemplate::setAttackSpeed(float attackSpeed) {
	this->attackSpeed = attackSpeed;
}

void SharedWeaponObjectTemplate::setForceCost(float forceCost) {
	this->forceCost = forceCost;
}

void SharedWeaponObjectTemplate::setHealthAttackCost(int healthAttackCost) {
	this->healthAttackCost = healthAttackCost;
}

void SharedWeaponObjectTemplate::setIdealAccuracy(int idealAccuracy) {
	this->idealAccuracy = idealAccuracy;
}

void SharedWeaponObjectTemplate::setIdealRange(int idealRange) {
	this->idealRange = idealRange;
}

void SharedWeaponObjectTemplate::setMaxDamage(int maxDamage) {
	this->maxDamage = maxDamage;
}

void SharedWeaponObjectTemplate::setMaxRange(int maxRange) {
	this->maxRange = maxRange;
}

void SharedWeaponObjectTemplate::setMaxRangeAccuracy(int maxRangeAccuracy) {
	this->maxRangeAccuracy = maxRangeAccuracy;
}

void SharedWeaponObjectTemplate::setMinDamage(int minDamage) {
	this->minDamage = minDamage;
}

void SharedWeaponObjectTemplate::setMindAttackCost(int mindAttackCost) {
	this->mindAttackCost = mindAttackCost;
}

void SharedWeaponObjectTemplate::setPointBlankAccuracy(int pointBlankAccuracy) {
	this->pointBlankAccuracy = pointBlankAccuracy;
}

void SharedWeaponObjectTemplate::setPointBlankRange(int pointBlankRange) {
	this->pointBlankRange = pointBlankRange;
}

void SharedWeaponObjectTemplate::setWoundsRatio(float woundsRatio) {
	this->woundsRatio = woundsRatio;
}

const Vector<String>* SharedWeaponObjectTemplate::getCertificationsRequired() const {
	return &certificationsRequired;
}

const Vector<String>* SharedWeaponObjectTemplate::getCreatureAccuracyModifiers() const {
	return &creatureAccuracyModifiers;
}

const Vector<String>* SharedWeaponObjectTemplate::getCreatureAimModifiers() const {
	return &creatureAimModifiers;
}

const Vector<String>* SharedWeaponObjectTemplate::getDamageModifiers() const {
	return &damageModifiers;
}

int SharedWeaponObjectTemplate::getDamageType() const {
	return damageType;
}

const Vector<String>* SharedWeaponObjectTemplate::getDefenderDefenseModifiers() const {
	return &defenderDefenseModifiers;
}

const Vector<String>* SharedWeaponObjectTemplate::getDefenderSecondaryDefenseModifiers() const {
	return &defenderSecondaryDefenseModifiers;
}

const Vector<String>* SharedWeaponObjectTemplate::getDefenderToughnessModifiers() const {
	return &defenderToughnessModifiers;
}

const Vector<String>* SharedWeaponObjectTemplate::getSpeedModifiers() const {
	return &speedModifiers;
}

void SharedWeaponObjectTemplate::setCertificationsRequired(Vector<String> certificationsRequired) {
	this->certificationsRequired = certificationsRequired;
}

void SharedWeaponObjectTemplate::setCreatureAccuracyModifiers(Vector<String> creatureAccuracyModifiers) {
	this->creatureAccuracyModifiers = creatureAccuracyModifiers;
}

void SharedWeaponObjectTemplate::setCreatureAimModifiers(Vector<String> creatureAimModifiers) {
	this->creatureAimModifiers = creatureAimModifiers;
}

void SharedWeaponObjectTemplate::setDamageModifiers(Vector<String> damageModifiers) {
	this->damageModifiers = damageModifiers;
}

void SharedWeaponObjectTemplate::setDamageType(int damageType) {
	this->damageType = damageType;
}

void SharedWeaponObjectTemplate::setDefenderDefenseModifiers(Vector<String> defenderDefenseModifiers) {
	this->defenderDefenseModifiers = defenderDefenseModifiers;
}

void SharedWeaponObjectTemplate::setDefenderSecondaryDefenseModifiers(Vector<String> defenderSecondaryDefenseModifiers) {
	this->defenderSecondaryDefenseModifiers = defenderSecondaryDefenseModifiers;
}

void SharedWeaponObjectTemplate::setDefenderToughnessModifiers(Vector<String> defenderToughnessModifiers) {
	this->defenderToughnessModifiers = defenderToughnessModifiers;
}

void SharedWeaponObjectTemplate::setSpeedModifiers(Vector<String> speedModifiers) {
	this->speedModifiers = speedModifiers;
}

int SharedWeaponObjectTemplate::getAttackType() const {
	return attackType;
}

const String& SharedWeaponObjectTemplate::getWeaponEffect() const {
	return weaponEffect.get();
}

int SharedWeaponObjectTemplate::getWeaponEffectIndex() const {
	return weaponEffectIndex;
}

void SharedWeaponObjectTemplate::setAttackType(int attackType) {
	this->attackType = attackType;
}

void SharedWeaponObjectTemplate::setWeaponEffect(String weaponEffect) {
	this->weaponEffect = weaponEffect;
}

void SharedWeaponObjectTemplate::setWeaponEffectIndex(int weaponEffectIndex) {
	this->weaponEffectIndex = weaponEffectIndex;
}

const String& SharedWeaponObjectTemplate::getCombatSpam() const {
	return combatSpam;
}

const String& SharedWeaponObjectTemplate::getAnimationType() const {
	return animationType;
}

uint32 SharedWeaponObjectTemplate::getWeaponType() const {
	return weaponType;
}

void SharedWeaponObjectTemplate::setWeaponType(uint32 weaponType) {
	this->weaponType = weaponType;
}