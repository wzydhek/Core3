/*
 * SharedStructureObjectTemplate.h
 *
 *  Created on: May 22, 2010
 *      Author: crush
 */

#pragma once

#include "templates/building/SharedBuildingObjectTemplate.h"

class CampStructureTemplate : public SharedBuildingObjectTemplate {
protected:
	uint16 experience;
	uint16 duration;
	uint16 radius;
	uint16 aggroMod;
	uint16 skillRequired;
	uint16 healthWoundRegenRate;
	uint16 actionWoundRegenRate;
	uint16 mindWoundRegenRate;

public:
	CampStructureTemplate();

	~CampStructureTemplate();

	void readObject(LuaObject* templateData);

	bool isCampStructureTemplate();

	int getDuration() const;

	int getExperience() const;

	int getRadius() const;

	int getAggroMod() const;

	int getSkillRequired() const;

	int getHealthWoundRegenRate();

	int getActionWoundRegenRate();

	int getMindWoundRegenRate();

};
