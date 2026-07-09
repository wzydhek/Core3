/*
 * CreatureTemplate.cpp
 *
 *  Created on: 22/01/2012
 *      Author: victor
 */

#include "CreatureTemplate.h"
#include "server/zone/managers/creature/CreatureTemplateManager.h"

CreatureTemplate::CreatureTemplate() {
	conversationTemplate = 0;
	kinetic = 0;
	energy = 0;
	electricity = 0;
	stun = 0;
	blast = 0;
	heat = 0;
	cold = 0;
	acid = 0;
	lightSaber = 0;

	scale = 1.f;

	objectName = "";
	randomNameType = 0;
	mobType = 0;
	randomNameTag = false;
	customName = "";
	planetMapCategory = 0;
	mapCategoryName = "";
	planetMapSubCategory = 0;
	mapSubCategoryName = "";
	socialGroup = "";
	faction = "";
	level = 0;
	chanceHit = 0.f;
	damageMin = 0;
	damageMax = 0;
	attackSpeed = 0.0f;
	specialDamageMult = 1.f;
	range = 0;
	baseXp = 0;
	baseHAM = 0;
	baseHAMmax = 0;
	armor = 0;
	meatType = "";
	meatAmount = 0;
	hideType = "";
	hideAmount = 0;
	boneType = "";
	boneAmount = 0;
	milkType = "";
	milk = 0.f;
	tamingChance = 0.f;
	ferocity = 0;
	aggroRadius = 0;
	pvpBitmask = 0;
	creatureBitmask = 0;
	diet = 0;
	optionsBitmask = 0;
	customAiMap = 0;
	tauntable = true;
	healerType = "";
	lightsaberColor = 0;

	primaryWeapon = "";
	secondaryWeapon = "";
	thrownWeapon = "";

	templates.removeAll();

	primaryAttacks = new CreatureAttackMap();
	secondaryAttacks = new CreatureAttackMap();

	aiTemplate = "example";
	defaultWeapon = "";
	defaultAttack = "defaultattack";
	controlDeviceTemplate = "object/intangible/pet/pet_control.iff";
	containerComponentTemplate = "";
	reactionStf = "";
	personalityStf = "";
}

CreatureTemplate::~CreatureTemplate() {
	templates.removeAll();

	delete primaryAttacks;
	primaryAttacks = nullptr;

	delete secondaryAttacks;
	secondaryAttacks = nullptr;
}

void CreatureTemplate::readObject(LuaObject* templateData) {
	conversationTemplate = String(templateData->getStringField("conversationTemplate").trim()).hashCode();
	objectName = templateData->getStringField("objectName").trim();
	randomNameType = templateData->getIntField("randomNameType");
	randomNameTag = templateData->getBooleanField("randomNameTag");

	mapCategoryName = String(templateData->getStringField("planetMapCategory").trim());
	planetMapCategory = mapCategoryName.hashCode();

	mapSubCategoryName = String(templateData->getStringField("planetMapSubCategory").trim());
	planetMapSubCategory = mapSubCategoryName.hashCode();

	mobType = templateData->getIntField("mobType");

	customName = templateData->getStringField("customName").trim();
	socialGroup = templateData->getStringField("socialGroup").trim();
	faction = templateData->getStringField("faction").trim().toLowerCase();
	level = templateData->getIntField("level");
	chanceHit = templateData->getFloatField("chanceHit");
	damageMin = templateData->getIntField("damageMin");
	damageMax = templateData->getIntField("damageMax");
	specialDamageMult = templateData->getFloatField("specialDamageMult");
	attackSpeed = templateData->getFloatField("attackSpeed");
	if (specialDamageMult < 0.001f) specialDamageMult = 1.f; // could use numeric_limit here, but this will prevent people from putting tiny modifiers in as well.
	baseXp = templateData->getIntField("baseXp");
	baseHAM = templateData->getIntField("baseHAM");
	baseHAMmax = templateData->getIntField("baseHAMmax");
	armor = templateData->getIntField("armor");
	meatType = templateData->getStringField("meatType").trim();
	meatAmount = templateData->getIntField("meatAmount");
	hideType = templateData->getStringField("hideType").trim();
	hideAmount = templateData->getIntField("hideAmount");
	boneType = templateData->getStringField("boneType").trim();
	boneAmount = templateData->getIntField("boneAmount");
	milk = templateData->getIntField("milk");
	tamingChance = templateData->getFloatField("tamingChance");
	ferocity = templateData->getIntField("ferocity");
	aggroRadius = templateData->getIntField("aggroRadius");
	pvpBitmask = templateData->getIntField("pvpBitmask");
	creatureBitmask = templateData->getIntField("creatureBitmask");
	diet = templateData->getIntField("diet");
	optionsBitmask = templateData->getIntField("optionsBitmask");
	patrolPathTemplate = templateData->getStringField("patrolPathTemplate");
	defaultWeapon = templateData->getStringField("defaultWeapon");
	tauntable = templateData->getBooleanField("tauntable", true);
	healerType = templateData->getStringField("healerType").trim();
	lightsaberColor = templateData->getIntField("lightsaberColor");

	if(!templateData->getStringField("defaultAttack").isEmpty())
		defaultAttack = templateData->getStringField("defaultAttack");

	if(!templateData->getStringField("customAiMap").isEmpty())
		customAiMap = templateData->getStringField("customAiMap").hashCode();

	scale = templateData->getFloatField("scale");

	if (!templateData->getStringField("milkType").isEmpty()) {
		milkType = templateData->getStringField("milkType").trim();
	}

	LuaObject res = templateData->getObjectField("resists");
	if (res.getTableSize() == 9) {
		kinetic = res.getFloatAt(1);
		energy = res.getFloatAt(2);
		blast = res.getFloatAt(3);
		heat = res.getFloatAt(4);
		cold = res.getFloatAt(5);
		electricity = res.getFloatAt(6);
		acid = res.getFloatAt(7);
		stun = res.getFloatAt(8);
		lightSaber = res.getFloatAt(9);
	}

	res.pop();

	LuaObject temps = templateData->getObjectField("templates");
	if (temps.isValidTable()) {
		for (int i = 1; i <= temps.getTableSize(); ++i) {
			String tempName = temps.getStringAt(i).trim();

			if (tempName.endsWith(".iff")) {
				templates.add(tempName);
				continue;
			}

			const Vector<String>& dressGroup = CreatureTemplateManager::instance()->getDressGroup(tempName);
			templates.addAll(dressGroup);
		}
	}

	temps.pop();

	LuaObject lootCollections = templateData->getObjectField("lootGroups");
	lootgroups.readObject(&lootCollections, level);
	lootCollections.pop();

	primaryWeapon = templateData->getStringField("primaryWeapon");
	secondaryWeapon = templateData->getStringField("secondaryWeapon");
	thrownWeapon = templateData->getStringField("thrownWeapon");

	LuaObject attackList = templateData->getObjectField("primaryAttacks");
	if (attackList.isValidTable()) {
		int size = attackList.getTableSize();
		lua_State* L = attackList.getLuaState();
		for (int i = 1; i <= size; ++i) {
			lua_rawgeti(L, -1, i);
			LuaObject atk(L);

			if (atk.isValidTable()) {
				int atkSize = atk.getTableSize();
				if (atkSize == 2) {
					String com = atk.getStringAt(1).trim();
					String arg = atk.getStringAt(2).trim();

					primaryAttacks->addAttack(com, arg);
				}
			}

			atk.pop();
		}
	}

	attackList.pop();

	attackList = templateData->getObjectField("secondaryAttacks");
	if (attackList.isValidTable()) {
		int size = attackList.getTableSize();
		lua_State* L = attackList.getLuaState();
		for (int i = 1; i <= size; ++i) {
			lua_rawgeti(L, -1, i);
			LuaObject atk(L);

			if (atk.isValidTable()) {
				int atkSize = atk.getTableSize();
				if (atkSize == 2) {
					String com = atk.getStringAt(1).trim();
					String arg = atk.getStringAt(2).trim();

					secondaryAttacks->addAttack(com, arg);
				}
			}

			atk.pop();
		}
	}

	attackList.pop();

	LuaObject hueTable = templateData->getObjectField("hues");
	if (hueTable.isValidTable()) {
		for (int i = 1; i <= hueTable.getTableSize(); ++i) {
			hues.add(hueTable.getIntAt(i));
		}
	}

	hueTable.pop();

	outfit = templateData->getStringField("outfit");

	aiTemplate = templateData->getStringField("aiTemplate");

	if(!templateData->getStringField("controlDeviceTemplate").isEmpty())
		controlDeviceTemplate = templateData->getStringField("controlDeviceTemplate");

	containerComponentTemplate = templateData->getStringField("containerComponentTemplate");

	reactionStf = templateData->getStringField("reactionStf");
	personalityStf = templateData->getStringField("personalityStf");
}

float CreatureTemplate::getKinetic() const {
	if (isSpecialProtection(SharedWeaponObjectTemplate::KINETIC))
		return kinetic - 100;
	else
		return kinetic;
}

float CreatureTemplate::getEnergy() const {
	if (isSpecialProtection(SharedWeaponObjectTemplate::ENERGY))
		return energy - 100;
	else
		return energy;
}

float CreatureTemplate::getElectricity() const {
	if (isSpecialProtection(SharedWeaponObjectTemplate::ELECTRICITY))
		return electricity - 100;
	else
		return electricity;
}

float CreatureTemplate::getStun() const {
	if (isSpecialProtection(SharedWeaponObjectTemplate::STUN))
		return stun - 100;
	else
		return stun;
}

float CreatureTemplate::getBlast() const {
	if (isSpecialProtection(SharedWeaponObjectTemplate::BLAST))
		return blast - 100;
	else
		return blast;
}

float CreatureTemplate::getHeat() const {
	if (isSpecialProtection(SharedWeaponObjectTemplate::HEAT))
		return heat - 100;
	else
		return heat;
}

float CreatureTemplate::getCold() const {
	if (isSpecialProtection(SharedWeaponObjectTemplate::COLD))
		return cold - 100;
	else
		return cold;
}

float CreatureTemplate::getAcid() const {
	if (isSpecialProtection(SharedWeaponObjectTemplate::ACID))
		return acid - 100;
	else
		return acid;
}

float CreatureTemplate::getLightSaber() const {
	if (isSpecialProtection(SharedWeaponObjectTemplate::LIGHTSABER))
		return lightSaber - 100;
	else
		return lightSaber;
}

bool CreatureTemplate::isStalker() const {
	return creatureBitmask & ObjectFlag::STALKER;
}

bool CreatureTemplate::isBaby() const {
	return creatureBitmask & ObjectFlag::BABY;
}

bool CreatureTemplate::isKiller() const {
	return creatureBitmask & ObjectFlag::KILLER;
}

bool CreatureTemplate::isHealer() const {
	return creatureBitmask & ObjectFlag::HEALER;
}

bool CreatureTemplate::isPack() const {
	return creatureBitmask & ObjectFlag::PACK;
}

bool CreatureTemplate::isHerd() const {
	return creatureBitmask & ObjectFlag::HERD;
}

float CreatureTemplate::getTame() const {
	return tamingChance;
}

const String& CreatureTemplate::getMeatType() const {
	return meatType;
}

const String& CreatureTemplate::getBoneType() const {
	return boneType;
}

const String& CreatureTemplate::getHideType() const {
	return hideType;
}

const String& CreatureTemplate::getMilkType() const {
	return milkType;
}

const String& CreatureTemplate::getCustomName() const {
	return customName;
}

float CreatureTemplate::getMilk() const {
	return milk;
}

float CreatureTemplate::getHideMax() const {
	return hideAmount;
}

float CreatureTemplate::getBoneMax() const {
	return boneAmount;
}

float CreatureTemplate::getMeatMax() const {
	return meatAmount;
}

unsigned int CreatureTemplate::getFerocity() const {
	return ferocity;
}

unsigned int CreatureTemplate::getArmor() const {
	return armor;
}

const String& CreatureTemplate::getObjectName() const {
	return objectName;
}

uint32 CreatureTemplate::getPlanetMapCategory() const {
	return planetMapCategory;
}

String CreatureTemplate::getPlanetMapCategoryName() const {
	return mapCategoryName;
}

uint32 CreatureTemplate::getPlanetMapSubCategory() const {
	return planetMapSubCategory;
}

String CreatureTemplate::getPlanetMapSubCategoryName() const {
	return mapSubCategoryName;
}

int CreatureTemplate::getRandomNameType() const {
	return randomNameType;
}

int CreatureTemplate::getMobType() const {
	return mobType;
}

bool CreatureTemplate::getRandomNameTag() const {
	return randomNameTag;
}

const String& CreatureTemplate::getSocialGroup() const {
	return socialGroup;
}

uint32 CreatureTemplate::getConversationTemplate() const {
	return conversationTemplate;
}

uint32 CreatureTemplate::getOptionsBitmask() const {
	return optionsBitmask;
}

uint64 CreatureTemplate::getCustomAiMap() {
	return customAiMap;
}

const String& CreatureTemplate::getFaction() const {
	return faction;
}

int CreatureTemplate::getLevel() const {
	return level;
}

float CreatureTemplate::getChanceHit() const {
	return chanceHit;
}

float CreatureTemplate::getScale() const {
	return scale;
}

int CreatureTemplate::getDamageMin() const {
	return damageMin;
}

int CreatureTemplate::getDamageMax() const {
	return damageMax;
}

float CreatureTemplate::getAttackSpeed() const {
	return attackSpeed;
}

float CreatureTemplate::getSpecialDamageMult() const {
	return specialDamageMult;
}

int CreatureTemplate::getRange() const {
	return range;
}

int CreatureTemplate::getBaseXp() const {
	return baseXp;
}

int CreatureTemplate::getBaseHAM() const {
	return baseHAM;
}

int CreatureTemplate::getBaseHAMmax() const {
	return baseHAMmax;
}

int CreatureTemplate::getRandomHue() const {
	int randHue = System::random(hues.size() - 1);
	return hues.get(randHue);
}

int CreatureTemplate::getHueCount() const {
	return hues.size();
}

int CreatureTemplate::getTotalHues() const {
	return hues.size();
}

int CreatureTemplate::getAggroRadius() const {
	return aggroRadius;
}

uint32 CreatureTemplate::getPvpBitmask() const {
	return pvpBitmask;
}

uint32 CreatureTemplate::getCreatureBitmask() const {
	return creatureBitmask;
}

uint32 CreatureTemplate::getDiet() const {
	return diet;
}

bool CreatureTemplate::isTauntable() const {
	return tauntable;
}

int CreatureTemplate::getLightsaberColor() const {
	return lightsaberColor;
}

const Vector<String>& CreatureTemplate::getTemplates() const {
	return templates;
}

const LootGroupCollection* CreatureTemplate::getLootGroups() const {
	return &lootgroups;
}

const String& CreatureTemplate::getPrimaryWeapon() const {
	return primaryWeapon;
}

const String& CreatureTemplate::getSecondaryWeapon() const {
	return secondaryWeapon;
}

const String& CreatureTemplate::getThrownWeapon() const {
	return thrownWeapon;
}

const CreatureAttackMap* CreatureTemplate::getPrimaryAttacks() const {
	return primaryAttacks;
}

const CreatureAttackMap* CreatureTemplate::getSecondaryAttacks() const {
	return secondaryAttacks;
}

const String& CreatureTemplate::getPatrolPathTemplate() const {
	return patrolPathTemplate;
}

void CreatureTemplate::setTemplateName(const String& t) {
	templateName = t;
}

const String& CreatureTemplate::getTemplateName() const {
	return templateName;
}

String& CreatureTemplate::getTemplateName() {
	return templateName;
}

bool CreatureTemplate::hasPatrolPathTemplate() const {
	return !patrolPathTemplate.isEmpty();
}

const String& CreatureTemplate::getOutfit() const {
	return outfit;
}

const String& CreatureTemplate::getAiTemplate() const {
	return aiTemplate;
}

const String& CreatureTemplate::getDefaultWeapon() const {
	return defaultWeapon;
}

const String& CreatureTemplate::getDefaultAttack() const {
	return defaultAttack;
}

const String& CreatureTemplate::getControlDeviceTemplate() const {
	return controlDeviceTemplate;
}

const String& CreatureTemplate::getContainerComponentTemplate() const {
	return containerComponentTemplate;
}

const String& CreatureTemplate::getReactionStf() const {
	return reactionStf;
}

const String& CreatureTemplate::getPersonalityStf() const {
	return personalityStf;
}

const String& CreatureTemplate::getHealerType() const {
	return healerType;
}

bool CreatureTemplate::isSpecialProtection(int resistType) const {
	switch (resistType) {
		case SharedWeaponObjectTemplate::KINETIC:
			return kinetic > 100;
			break;
		case SharedWeaponObjectTemplate::ENERGY:
			return energy > 100;
			break;
		case SharedWeaponObjectTemplate::ELECTRICITY:
			return electricity > 100;
			break;
		case SharedWeaponObjectTemplate::STUN:
			return stun > 100;
			break;
		case SharedWeaponObjectTemplate::BLAST:
			return blast > 100;
			break;
		case SharedWeaponObjectTemplate::HEAT:
			return heat > 100;
			break;
		case SharedWeaponObjectTemplate::COLD:
			return cold > 100;
			break;
		case SharedWeaponObjectTemplate::ACID:
			return acid > 100;
			break;
		case SharedWeaponObjectTemplate::LIGHTSABER:
			return lightSaber > 100;
			break;
	}

	return false;
}