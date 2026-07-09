#include "TrapTemplate.h"

TrapTemplate::TrapTemplate() {
	skillRequired = 0;
	healthCost = 0;
	actionCost = 0;
	mindCost = 0;
	poolToDamage = 0;
	maxRange = 0;
	minDamage = 0;
	maxDamage = 0;
	duration = 0;
	state = 0;
	animation = "";
	successMessage = "";
	failMessage = "";
	startSpam = "";
	stopSpam = "";
	defenseMod = "";
	areaOfEffect = false;
}

TrapTemplate::~TrapTemplate() {
}

void TrapTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	skillRequired = templateData->getIntField("skillRequired");
	healthCost = templateData->getIntField("healthCost");
	actionCost = templateData->getIntField("actionCost");
	mindCost = templateData->getIntField("mindCost");
	maxRange = templateData->getFloatField("maxRange");
	poolToDamage = templateData->getShortField("poolToDamage");
	minDamage = templateData->getFloatField("minDamage");
	maxDamage = templateData->getFloatField("maxDamage");
	duration = templateData->getIntField("duration");
	state = templateData->getLongField("state");
	animation = templateData->getStringField("animation");
	successMessage = templateData->getStringField("successMessage");
	failMessage = templateData->getStringField("failMessage");
	startSpam = templateData->getStringField("startSpam");
	stopSpam = templateData->getStringField("stopSpam");
	defenseMod = templateData->getStringField("defenseMod");
	areaOfEffect = templateData->getBooleanField("areaOfEffect");
}

int TrapTemplate::getActionCost() {
	return actionCost;
}

int TrapTemplate::getDuration() {
	return duration;
}

const String& TrapTemplate::getAnimation() {
	return animation;
}

const String& TrapTemplate::getSuccessMessage() {
	return successMessage;
}

const String& TrapTemplate::getFailMessage() {
	return failMessage;
}

const String& TrapTemplate::getStartSpam() {
	return startSpam;
}

const String& TrapTemplate::getStopSpam() {
	return stopSpam;
}

const String& TrapTemplate::getDefenseMod() {
	return defenseMod;
}

int TrapTemplate::getHealthCost() {
	return healthCost;
}

float TrapTemplate::getMaxDamage() {
	return maxDamage;
}

float TrapTemplate::getMaxRange() {
	return maxRange;
}

float TrapTemplate::getMinDamage() {
	return minDamage;
}

int TrapTemplate::getMindCost() {
	return mindCost;
}

int TrapTemplate::getSkillRequired() {
	return skillRequired;
}

short TrapTemplate::getPoolToDamage() {
	return poolToDamage;
}

uint64 TrapTemplate::getState() {
	return state;
}

bool TrapTemplate::isAoeTrap() {
	return areaOfEffect;
}