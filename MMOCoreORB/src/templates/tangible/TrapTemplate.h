/*
 * TrapTemplate.h
 *
 *  Created on: Jan 16, 2012
 *  Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class TrapTemplate: public SharedTangibleObjectTemplate {
protected:
	int skillRequired;
	int healthCost;
	int actionCost;
	int mindCost;
	float maxRange;
	short poolToDamage;
	float minDamage;
	float maxDamage;
	int duration;
	String defenseMod;
	uint64 state;
	String animation;
	String successMessage;
	String failMessage;
	String startSpam;
	String stopSpam;
	bool areaOfEffect;

public:
	TrapTemplate();

	~TrapTemplate();

	void readObject(LuaObject* templateData);

	int getActionCost();

	int getDuration();

	const String& getAnimation();

	const String& getSuccessMessage();

	const String& getFailMessage();

	const String& getStartSpam();

	const String& getStopSpam();

	const String& getDefenseMod();

	int getHealthCost();

	float getMaxDamage();

	float getMaxRange();

	float getMinDamage();

	int getMindCost();

	int getSkillRequired();

	short getPoolToDamage();

	uint64 getState();

	bool isAoeTrap();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
