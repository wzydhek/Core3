/*
 * DotPackTemplate.h
 *
 *  Created on: 10/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class DotPackTemplate : public SharedTangibleObjectTemplate {
	float effectiveness;
	float range;
	float area;
	float rangeMod;
	float potency;
	int medicineUse;
	uint32 duration;
	uint32 pool;
	uint32 dotType;
	String commandToExecute;
	bool hasArea;

public:
	DotPackTemplate();

	~DotPackTemplate();

	void readObject(LuaObject* templateData);

	int getMedicineUse();

	float getEffectiveness();

	uint32 getPool();

	float getRange();

	float getArea();

	bool isArea();

	float getRangeMod();

	uint32 getDuration();

	float getPotency();

	uint32 getDotType();

	String& getCommandToExecute();

	bool isDotPackTemplate();
};
