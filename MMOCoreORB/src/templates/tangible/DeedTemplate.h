/*
 * DeedTemplate.h
 *
 *  Created on: May 8, 2010
 *      Author: crush
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class DeedTemplate : public SharedTangibleObjectTemplate {
	String generatedObjectTemplate;

public:
	DeedTemplate() {

	}

	~DeedTemplate() {

	}

	void readObject(LuaObject* templateData) {
		SharedTangibleObjectTemplate::readObject(templateData);

		generatedObjectTemplate = templateData->getStringField("generatedObjectTemplate");
	}

	inline const String& getGeneratedObjectTemplate() const {
		return generatedObjectTemplate;
	}
};
