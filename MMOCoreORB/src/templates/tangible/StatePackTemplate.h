/*
 * StatePackTemplate.h
 *
 *  Created on: 12/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

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

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
