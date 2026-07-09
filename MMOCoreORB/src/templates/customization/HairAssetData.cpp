#include "HairAssetData.h"

HairAssetData::HairAssetData() {
	skillModValue = 0;
	availableAtCreation = 0;
}

void HairAssetData::readObject(DataTableRow* row) {
	row->getValue(0, sharedTemplate);
	row->getValue(1, playerTemplate);
	row->getValue(2, skillModValue);
	row->getValue(3, availableAtCreation);
	row->getValue(4, serverTemplate);
	row->getValue(5, serverPlayerTemplate);
}

bool HairAssetData::isAvailableAtCreation() const {
	return availableAtCreation;
}

String HairAssetData::getPlayerTemplate() const {
	return playerTemplate;
}

String HairAssetData::getServerPlayerTemplate() const {
	return serverPlayerTemplate;
}

void HairAssetData::setServerPlayerTemplate(const String& serverPlayerTemplate) {
	this->serverPlayerTemplate = serverPlayerTemplate;
}

String HairAssetData::getServerTemplate() const {
	return serverTemplate;
}

String HairAssetData::getSharedTemplate() const {
	return sharedTemplate;
}

int HairAssetData::getSkillModValue() const {
	return skillModValue;
}