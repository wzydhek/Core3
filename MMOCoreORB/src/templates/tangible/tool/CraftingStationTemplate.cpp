#include "CraftingStationTemplate.h"

CraftingStationTemplate::CraftingStationTemplate() : stationType(0), complexityLevel(0) {
}

CraftingStationTemplate::~CraftingStationTemplate() {
}

void CraftingStationTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	stationType = templateData->getIntField("stationType");
	complexityLevel = templateData->getIntField("complexityLevel");
}

int CraftingStationTemplate::getStationType() const {
	return stationType;
}

int CraftingStationTemplate::getComplexityLevel() const {
	return complexityLevel;
}

bool CraftingStationTemplate::isCraftingStationTemplate() const {
	return true;
}