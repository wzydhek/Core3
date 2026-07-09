/*
 * WoundPackTemplate.h
 *
 *  Created on: 11/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class WoundPackTemplate : public SharedTangibleObjectTemplate {
	int medicineUse;
	float effectiveness;
	byte attribute;

public:
	WoundPackTemplate();

	~WoundPackTemplate();

	void readObject(LuaObject* templateData);

	int getMedicineUse();

	float getEffectiveness();

	byte getAttribute();

	bool isWoundPackTemplate();
};
