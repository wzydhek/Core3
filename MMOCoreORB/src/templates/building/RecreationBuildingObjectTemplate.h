/*
 * RecreationBuildingObject.h
 *
 *  Created on: 14/01/2012
 *      Author: kyle
 */

#pragma once

#include "templates/building/SharedBuildingObjectTemplate.h"

class RecreationBuildingObjectTemplate : public SharedBuildingObjectTemplate {
	int medicalRating;
	int healthWoundRegenRate;
	int actionWoundRegenRate;
	int mindWoundRegenRate;

public:
	RecreationBuildingObjectTemplate() : medicalRating(0), healthWoundRegenRate(0), actionWoundRegenRate(0), mindWoundRegenRate(0) {
	}

	~RecreationBuildingObjectTemplate() {
	}

	void readObject(LuaObject* templateData) {
		SharedBuildingObjectTemplate::readObject(templateData);

		medicalRating = templateData->getIntField("medicalRating");
		healthWoundRegenRate = templateData->getIntField("healthWoundRegenRate");
		actionWoundRegenRate = templateData->getIntField("actionWoundRegenRate");
		mindWoundRegenRate = templateData->getIntField("mindWoundRegenRate");

	}

	bool isRecreationBuildingObjectTemplate() {
		return true;
	}

	inline int getMedicalRating() {
		return medicalRating;
	}

	inline int getHealthWoundRegenRate() {
		return healthWoundRegenRate;
	}

	inline int getActionWoundRegenRate() {
		return actionWoundRegenRate;
	}

	inline int getMindWoundRegenRate() {
		return mindWoundRegenRate;
	}
};
