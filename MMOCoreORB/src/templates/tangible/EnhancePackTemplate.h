/*
 * EnhancePackTemplate.h
 *
 *  Created on: 10/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class EnhancePackTemplate : public SharedTangibleObjectTemplate {
	int medicineUse;
	float effectiveness;
	float absorption;
	float duration;
	byte attribute;

public:
	EnhancePackTemplate();

	~EnhancePackTemplate();

	void readObject(LuaObject* templateData);

	int getMedicineUse();

	float getEffectiveness();

	float getAbsorption();

	byte getAttribute();

	float getDuration();

	bool isEnhancePackTemplate();
};
