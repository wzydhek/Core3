/*
 * WoundPackTemplate.h
 *
 *  Created on: 11/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

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

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
