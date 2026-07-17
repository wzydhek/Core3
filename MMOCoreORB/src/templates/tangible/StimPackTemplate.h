/*
 * StimPackTemplate.h
 *
 *  Created on: 10/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class StimPackTemplate : public SharedTangibleObjectTemplate {
	int medicineUse;
	int medicineClass;
	float effectiveness;
	Vector<byte> attributes;

public:
	const static int STIM_A = 1;
	const static int STIM_B = 2;
	const static int STIM_C = 3;
	const static int STIM_D = 4;
	const static int STIM_E = 5;

	StimPackTemplate();

	~StimPackTemplate();

	void readObject(LuaObject* templateData);

	int getMedicineUse();

	float getEffectiveness();

	bool isStimPackTemplate();

	int getMedicineClass();

	Vector<byte> getAttributes();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
