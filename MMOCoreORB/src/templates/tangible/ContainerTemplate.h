/*
 * ContainerTemplate.h
 *
 *  Created on: Mar 9, 2011
 *      Author: polonel
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class ContainerTemplate : public SharedTangibleObjectTemplate {
	bool lock;

public:
	ContainerTemplate() : lock(false) {

	}

	~ContainerTemplate() {

	}

	void readObject(LuaObject* templateData) {
		SharedTangibleObjectTemplate::readObject(templateData);

		lock = templateData->getByteField("locked");

    }

	inline bool getLocked() const {
		return lock;
	}

};
