/*
 * CreatureHabitatTemplate.h
 *
 *  Created on: March 16, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class CreatureHabitatTemplate: public SharedTangibleObjectTemplate {

public:
	CreatureHabitatTemplate();

	~CreatureHabitatTemplate();

	void readObject(LuaObject* templateData);

	bool isCreatureHabitatTemplate() const;

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;