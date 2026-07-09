/*
 * StatePackTemplate.h
 *
 *  Created on: 12/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class StatePackTemplate : public SharedTangibleObjectTemplate {
	int medicineUse;
	uint64 state;

public:
	StatePackTemplate();

	~StatePackTemplate();

	void readObject(LuaObject* templateData);

	int getMedicineUse();

	uint64 getState();

	bool isStatePackTemplate();
};
