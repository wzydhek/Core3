/*
 * RangedRangedRangedStimPackTemplate.h
 *
 *  Created on: 10/08/2010
 *      Author: victor
 */

#pragma once

#include "StimPackTemplate.h"

class RangedStimPackTemplate : public StimPackTemplate {
	float effectiveness;
	float range;
	float area;
	float rangeMod;

public:
	RangedStimPackTemplate();

	~RangedStimPackTemplate();

	void readObject(LuaObject* templateData);

	float getEffectiveness();

	float getRange();

	float getArea();

	float getRangeMod();

	bool isRangedStimPackTemplate();
};
