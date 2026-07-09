#include "HospitalBuildingObjectTemplate.h"

HospitalBuildingObjectTemplate::HospitalBuildingObjectTemplate() : medicalRating(0), healthWoundRegenRate(0), actionWoundRegenRate(0), mindWoundRegenRate(0) {
}

HospitalBuildingObjectTemplate::~HospitalBuildingObjectTemplate() {
}

void HospitalBuildingObjectTemplate::readObject(LuaObject* templateData) {
	SharedBuildingObjectTemplate::readObject(templateData);

	medicalRating = templateData->getIntField("medicalRating");
	healthWoundRegenRate = templateData->getIntField("healthWoundRegenRate");
	actionWoundRegenRate = templateData->getIntField("actionWoundRegenRate");
	mindWoundRegenRate = templateData->getIntField("mindWoundRegenRate");
}

bool HospitalBuildingObjectTemplate::isHospitalBuildingObjectTemplate() {
	return true;
}

int HospitalBuildingObjectTemplate::getMedicalRating() {
	return medicalRating;
}

int HospitalBuildingObjectTemplate::getHealthWoundRegenRate() {
	return healthWoundRegenRate;
}

int HospitalBuildingObjectTemplate::getActionWoundRegenRate() {
	return actionWoundRegenRate;
}

int HospitalBuildingObjectTemplate::getMindWoundRegenRate() {
	return mindWoundRegenRate;
}