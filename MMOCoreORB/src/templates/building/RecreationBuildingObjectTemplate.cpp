#include "RecreationBuildingObjectTemplate.h"

RecreationBuildingObjectTemplate::RecreationBuildingObjectTemplate() : medicalRating(0), healthWoundRegenRate(0), actionWoundRegenRate(0), mindWoundRegenRate(0) {
}

RecreationBuildingObjectTemplate::~RecreationBuildingObjectTemplate() {
}

void RecreationBuildingObjectTemplate::readObject(LuaObject* templateData) {
	SharedBuildingObjectTemplate::readObject(templateData);

	medicalRating = templateData->getIntField("medicalRating");
	healthWoundRegenRate = templateData->getIntField("healthWoundRegenRate");
	actionWoundRegenRate = templateData->getIntField("actionWoundRegenRate");
	mindWoundRegenRate = templateData->getIntField("mindWoundRegenRate");
}

bool RecreationBuildingObjectTemplate::isRecreationBuildingObjectTemplate() {
	return true;
}

int RecreationBuildingObjectTemplate::getMedicalRating() {
	return medicalRating;
}

int RecreationBuildingObjectTemplate::getHealthWoundRegenRate() {
	return healthWoundRegenRate;
}

int RecreationBuildingObjectTemplate::getActionWoundRegenRate() {
	return actionWoundRegenRate;
}

int RecreationBuildingObjectTemplate::getMindWoundRegenRate() {
	return mindWoundRegenRate;
}