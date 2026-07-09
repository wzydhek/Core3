/*
 * CurePackTemplate.h
 *
 *  Created on: 10/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class CurePackTemplate : public SharedTangibleObjectTemplate {
	float effectiveness;
	uint64 state;
	float area;
	String commandToExecute;
	int medicineUse;

public:
	CurePackTemplate();

	~CurePackTemplate();

	void readObject(LuaObject* templateData);

	float getEffectiveness();

	uint64 getState();

	float getArea();

	int getMedicineUse();

	String& getCommandToExecute();

	bool isCurePackTemplate();
};
