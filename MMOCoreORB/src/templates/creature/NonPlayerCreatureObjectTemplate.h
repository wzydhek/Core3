/*
 * NonPlayerCreatureObjectTemplate.h
 *
 *  Created on: 10/07/2010
 *      Author: victor
 */

#pragma once

#include "templates/creature/SharedCreatureObjectTemplate.h"

class NonPlayerCreatureObjectTemplate : public SharedCreatureObjectTemplate {

public:

	NonPlayerCreatureObjectTemplate() {
	}

	virtual ~NonPlayerCreatureObjectTemplate() {
	}

	void readObject(LuaObject* templateData) {
		SharedCreatureObjectTemplate::readObject(templateData);
	}

	bool isNonPlayerCreatureObjectTemplate() {
		return true;
	}
};
