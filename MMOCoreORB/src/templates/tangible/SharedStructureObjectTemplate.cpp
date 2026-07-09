/*
 * SharedStructureObjectTemplate.cpp
 *
 *  Created on: May 22, 2010
 *      Author: crush
 */


#include "SharedStructureObjectTemplate.h"

SharedStructureObjectTemplate::SharedStructureObjectTemplate() {
	baseMaintenanceRate = 0;
	basePowerRate = 0;

	lotSize = 0;
	cityRankRequired = 0;

	uniqueStructure = false;

	// If it has a maintenance rate, then it is a civic structure.
	cityMaintenanceBase = 0;
	cityMaintenanceRate = 0;
}

SharedStructureObjectTemplate::~SharedStructureObjectTemplate() {
}

void SharedStructureObjectTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	lotSize = templateData->getByteField("lotSize");

	baseMaintenanceRate = templateData->getIntField("baseMaintenanceRate");

	basePowerRate = templateData->getIntField("basePowerRate");

	LuaObject allowzones = templateData->getObjectField("allowedZones");
	allowedZones.removeAll(); //Make sure it's empty...

	for (int i = 1; i <= allowzones.getTableSize(); ++i) {
		allowedZones.put(allowzones.getStringAt(i));
	}

	allowzones.pop();

	cityRankRequired = templateData->getByteField("cityRankRequired");

	constructionMarkerTemplate = templateData->getStringField("constructionMarker");

	abilityRequired = templateData->getStringField("abilityRequired");

	uniqueStructure = templateData->getBooleanField("uniqueStructure");

	cityMaintenanceBase = templateData->getIntField("cityMaintenanceBase");

	cityMaintenanceRate = templateData->getIntField("cityMaintenanceRate");
}

uint8 SharedStructureObjectTemplate::getLotSize() const {
	return lotSize;
}

bool SharedStructureObjectTemplate::isAllowedZone(const String& zoneName) {
	return allowedZones.contains(zoneName);
}

bool SharedStructureObjectTemplate::isCivicStructure() const {
	return (cityMaintenanceBase > 0);
}

bool SharedStructureObjectTemplate::isCommercialStructure() const {
	return (baseMaintenanceRate > 0 && cityRankRequired > 0);
}

bool SharedStructureObjectTemplate::isUniqueStructure() const {
	return uniqueStructure;
}

int SharedStructureObjectTemplate::getCityMaintenanceBase() const {
	return cityMaintenanceBase;
}

int SharedStructureObjectTemplate::getCityMaintenanceRate() const {
	return cityMaintenanceRate;
}

int SharedStructureObjectTemplate::getCityMaintenanceAtRank(int rank) const {
	return cityMaintenanceBase + cityMaintenanceRate * rank;
}

int SharedStructureObjectTemplate::getTotalAllowedZones() const {
	return allowedZones.size();
}

String SharedStructureObjectTemplate::getAllowedZone(int i) const {
	return allowedZones.get(i);
}

int SharedStructureObjectTemplate::getBaseMaintenanceRate() const {
	return baseMaintenanceRate;
}

int SharedStructureObjectTemplate::getBasePowerRate() const {
	return basePowerRate;
}

const String& SharedStructureObjectTemplate::getAbilityRequired() const {
	return abilityRequired;
}

uint8 SharedStructureObjectTemplate::getCityRankRequired() const {
	return cityRankRequired;
}

const String& SharedStructureObjectTemplate::getConstructionMarkerTemplate() const {
	return constructionMarkerTemplate;
}

bool SharedStructureObjectTemplate::isPublicStructure() const {
	return false;
}

bool SharedStructureObjectTemplate::isSharedStructureObjectTemplate() {
	return true;
}