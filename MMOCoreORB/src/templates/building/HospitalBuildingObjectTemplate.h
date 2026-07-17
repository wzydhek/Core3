/*
 * HospitalBuildingObject.h
 *
 *  Created on: 14/01/2012
 *      Author: kyle
 */

#pragma once

#include "templates/building/SharedBuildingObjectTemplate.h"

namespace templates {
namespace building {

class HospitalBuildingObjectTemplate : public SharedBuildingObjectTemplate {
	int medicalRating;
	int healthWoundRegenRate;
	int actionWoundRegenRate;
	int mindWoundRegenRate;

public:
	HospitalBuildingObjectTemplate();

	~HospitalBuildingObjectTemplate();

	void readObject(LuaObject* templateData);

	bool isHospitalBuildingObjectTemplate();

	int getMedicalRating();

	int getHealthWoundRegenRate();

	int getActionWoundRegenRate();

	int getMindWoundRegenRate();
};

} // namespace building
} // namespace templates

using namespace templates::building;
