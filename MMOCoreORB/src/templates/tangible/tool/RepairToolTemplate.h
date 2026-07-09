/*
 * RepairToolTemplate.h
 *
 *  Created on: Mar 21, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class RepairToolTemplate : public SharedTangibleObjectTemplate {
	uint32 mask;
	String boostSkill;
	String boostSkillMod;
	int stationType;

public:
	RepairToolTemplate();

	~RepairToolTemplate();

	void readObject(LuaObject* templateData) override;

	uint32 getRepairType() const;

	const String& getSkill() const;

	const String& getSkillMod() const;

	int getStationType() const;

	bool isRepairToolTemplate() const override;

};
