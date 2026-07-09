#include "DroidCommandData.h"

DroidCommandData::DroidCommandData(String command, String notifyString, float delay, int component, float energyModifier, float generalModifier, float incurDamage, float frontReinforcePercent, float capacitorReinforcePercent, float frontRatio) : Object() {
	commandName = command;
	stringID = notifyString;
	delayModifier = delay;
	componentType = component;
	energyEfficiency = energyModifier;
	generalEfficiency = generalModifier;
	damage = incurDamage;
	frontReinforceRatio = frontReinforcePercent;
	capacitorReinforcePercentage = capacitorReinforcePercent;
	frontShieldRatio = frontRatio;
}

DroidCommandData::~DroidCommandData() {
}

const String& DroidCommandData::getCommandName() const {
	return commandName;
}

const String& DroidCommandData::getStringID() const {
	return stringID;
}

float DroidCommandData::getDelayModifier() const {
	return delayModifier;
}

int DroidCommandData::getComponentType() const {
	return componentType;
}

float DroidCommandData::getEnergyEfficiency() const {
	return energyEfficiency;
}

float DroidCommandData::getGeneralEfficiency() const {
	return generalEfficiency;
}

float DroidCommandData::getDamage() const {
	return damage;
}

float DroidCommandData::getFrontReinforceRatio() const {
	return frontReinforceRatio;
}

float DroidCommandData::getCapacitorReinforcePercentage() const {
	return capacitorReinforcePercentage;
}

float DroidCommandData::getFrontShieldRatio() const {
	return frontShieldRatio;
}