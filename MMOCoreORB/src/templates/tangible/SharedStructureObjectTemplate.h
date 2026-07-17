/*
 * SharedStructureObjectTemplate.h
 *
 *  Created on: May 22, 2010
 *      Author: crush
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class SharedStructureObjectTemplate : public SharedTangibleObjectTemplate {
protected:
	SortedVector<String> allowedZones;

	String constructionMarkerTemplate;
	String abilityRequired;

	int baseMaintenanceRate;
	int basePowerRate;

	uint8 lotSize;
	uint8 cityRankRequired;

	bool uniqueStructure;

	//If it has a maintenance rate, then it is a civic structure.
	int cityMaintenanceBase;
	int cityMaintenanceRate;

public:
	SharedStructureObjectTemplate();

	~SharedStructureObjectTemplate();

	void readObject(LuaObject* templateData);

	uint8 getLotSize() const;

	bool isAllowedZone(const String& zoneName);

	bool isCivicStructure() const;

	bool isCommercialStructure() const;

	bool isUniqueStructure() const;

	int getCityMaintenanceBase() const;

	int getCityMaintenanceRate() const;

	int getCityMaintenanceAtRank(int rank) const;

	int getTotalAllowedZones() const;

	String getAllowedZone(int i) const;

	int getBaseMaintenanceRate() const;

	int getBasePowerRate() const;

	const String& getAbilityRequired() const;

	uint8 getCityRankRequired() const;

	const String& getConstructionMarkerTemplate() const;

	virtual bool isPublicStructure() const;

	virtual bool isSharedStructureObjectTemplate();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
