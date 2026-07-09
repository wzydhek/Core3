/*
 * CreatureHabitatTemplate.h
 *
 *  Created on: March 16, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class CreatureHabitatTemplate: public SharedTangibleObjectTemplate {

public:
	CreatureHabitatTemplate();

	~CreatureHabitatTemplate();

	void readObject(LuaObject* templateData);

	bool isCreatureHabitatTemplate() const;

};
