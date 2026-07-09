/*
 * ShipAgentTemplate.cpp
 *
 * Created on: 2024/11/01
 * Author: Hakry
 */

#include "ShipAgentTemplate.h"
#include "server/zone/managers/ship/ShipAgentTemplateManager.h"

// Constructor
ShipAgentTemplate::ShipAgentTemplate() {
	templateName = "";

	shipTemplate = "";
	pilotTemplate = "";
	shipType = "";

	experience = 0;

	lootChance = 0.f;
	lootRolls = 0;
	lootTable = "";

	minCredits = 0;
	maxCredits = 0;

	aggressive = 0;

	spaceFaction = "";

	imperialFactionReward = 0;
	rebelFactionReward = 0;

	color1 = 0;
	color2 = 0;
	texture = 0;

	questLoot = "";
	interiorChassis = "";
	formationLocation = 0;
	appearance = "";

	tauntType = "";
	tauntAttackChance = 0.f;
	tauntDefendChance = 0.f;
	tauntDieChance = 0.f;
	tauntAggressiveness = 0.f;

	pvpBitmask = 0;
	shipBitmask = 0;
	optionsBitmask = 0;

	customShipAiMap = 0;

	conversationTemplate = 0;
	conversationMobile = 0;
	conversationMessage = 0;

	cargoString = "";
}

// Destructor
ShipAgentTemplate::~ShipAgentTemplate() {
}

void ShipAgentTemplate::readObject(LuaObject* templateData) {
	shipTemplate = templateData->getStringField("template").trim();
	pilotTemplate = templateData->getStringField("pilotTemplate").trim();
	shipType = templateData->getStringField("shipType").trim();

	experience = templateData->getIntField("experience");

	lootChance = templateData->getFloatField("lootChance");
	lootRolls = templateData->getIntField("lootRolls");
	lootTable = templateData->getStringField("lootTable").trim();

	minCredits = templateData->getIntField("minCredits");
	maxCredits = templateData->getIntField("maxCredits");

	aggressive = templateData->getIntField("aggressive");

	spaceFaction = templateData->getStringField("spaceFaction").trim();

	// Vector<String> alliedFactions;
	LuaObject allies = templateData->getObjectField("alliedFactions");

	if (allies.isValidTable()) {
		for (int i = 1; i <= allies.getTableSize(); ++i) {
			String ally = allies.getStringAt(i).trim();

			alliedFactions.add(ally);
		}
	}

	allies.pop();

	// Vector<String> enemyFactions;
	LuaObject enemies = templateData->getObjectField("enemyFactions");

	if (enemies.isValidTable()) {
		for (int i = 1; i <= enemies.getTableSize(); ++i) {
			String enemy = enemies.getStringAt(i).trim();

			enemyFactions.add(enemy);
		}
	}

	enemies.pop();

	imperialFactionReward = templateData->getIntField("imperialFactionReward");
	rebelFactionReward = templateData->getIntField("rebelFactionReward");

	color1 = templateData->getIntField("color1");
	color2 = templateData->getIntField("color2");
	texture = templateData->getIntField("texture");

	questLoot = templateData->getStringField("questLoot").trim();
	interiorChassis = templateData->getStringField("interiorChassis").trim();
	formationLocation = templateData->getIntField("formationLocation");
	appearance = templateData->getStringField("appearance").trim();

	tauntType = templateData->getStringField("tauntType").trim();
	tauntAttackChance = templateData->getFloatField("tauntAttackChance");
	tauntDefendChance = templateData->getFloatField("tauntDefendChance");
	tauntDieChance = templateData->getFloatField("tauntDieChance");
	tauntAggressiveness = templateData->getFloatField("tauntAggressiveness");

	pvpBitmask = templateData->getIntField("pvpBitmask");
	shipBitmask = templateData->getIntField("shipBitmask");
	optionsBitmask = templateData->getIntField("optionsBitmask");

	if (!templateData->getStringField("customShipAiMap").isEmpty()) {
		customShipAiMap = templateData->getStringField("customShipAiMap").hashCode();
	}

	conversationTemplate = String(templateData->getStringField("conversationTemplate").trim()).hashCode();
	conversationMobile = String(templateData->getStringField("conversationMobile").trim()).hashCode();
	conversationMessage = String(templateData->getStringField("conversationMessage").trim()).hashCode();

	cargoString = templateData->getStringField("cargoString").trim();
}

void ShipAgentTemplate::setTemplateName(const String& t) {
	templateName = t;
}

// Accessors
String ShipAgentTemplate::getTemplateName() const {
	return templateName;
}

String ShipAgentTemplate::getShipTemplate() const {
	return shipTemplate;
}

String ShipAgentTemplate::getPilotTemplate() const {
	return pilotTemplate;
}

String ShipAgentTemplate::getShipType() const {
	return shipType;
}

int ShipAgentTemplate::getExperience() const {
	return experience;
}

float ShipAgentTemplate::getLootChance() const {
	return lootChance;
}

int ShipAgentTemplate::getLootRolls() const {
	return lootRolls;
}

String ShipAgentTemplate::getLootTable() const {
	return lootTable;
}

int ShipAgentTemplate::getMinCredits() const {
	return minCredits;
}

int ShipAgentTemplate::getMaxCredits() const {
	return maxCredits;
}

int ShipAgentTemplate::getAggressive() const {
	return aggressive;
}

String ShipAgentTemplate::getSpaceFaction() const {
	return spaceFaction;
}

int ShipAgentTemplate::getTotalAlliedFactions() const {
	return alliedFactions.size();
}

String ShipAgentTemplate::getAlliedFaction(int index) const {
	return alliedFactions.get(index);
}

int ShipAgentTemplate::getTotalEnemyFactions() const {
	return enemyFactions.size();
}

String ShipAgentTemplate::getEnemyFaction(int index) const {
	return enemyFactions.get(index);
}

int ShipAgentTemplate::getImperialFactionReward() const {
	return imperialFactionReward;
}

int ShipAgentTemplate::getRebelFactionReward() const {
	return rebelFactionReward;
}

int ShipAgentTemplate::getColor1() const {
	return color1;
}

int ShipAgentTemplate::getColor2() const {
	return color2;
}

int ShipAgentTemplate::getTexture() const {
	return texture;
}

String ShipAgentTemplate::getQuestLoot() const {
	return questLoot;
}

String ShipAgentTemplate::getInteriorChassis() const {
	return interiorChassis;
}

int ShipAgentTemplate::getFormationLocation() const {
	return formationLocation;
}

String ShipAgentTemplate::getAppearance() const {
	return appearance;
}

String ShipAgentTemplate::getTauntType() const {
	return tauntType;
}

float ShipAgentTemplate::getTauntAttackChance() const {
	return tauntAttackChance;
}

float ShipAgentTemplate::getTauntDefendChance() const {
	return tauntDefendChance;
}

float ShipAgentTemplate::getTauntDieChance() const {
	return tauntDieChance;
}

float ShipAgentTemplate::getTauntAggressiveness() const {
	return tauntAggressiveness;
}

uint32 ShipAgentTemplate::getPvpBitmask() const {
	return pvpBitmask;
}

uint32 ShipAgentTemplate::getShipBitmask() const {
	return shipBitmask;
}

uint32 ShipAgentTemplate::getOptionsBitmask() const {
	return optionsBitmask;
}

uint64 ShipAgentTemplate::getCustomShipAiMap() const {
	return customShipAiMap;
}

uint32 ShipAgentTemplate::getConversationTemplate() const {
	return conversationTemplate;
}

uint32 ShipAgentTemplate::getConversationMobile() const {
	return conversationMobile;
}

uint32 ShipAgentTemplate::getConversationMessage() const {
	return conversationMessage;
}

String ShipAgentTemplate::getCargoString() const {
	return cargoString;
}