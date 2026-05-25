/*
 * LiveSampleTemplate.h
 *
 *  Created on: March 16, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class LiveSampleTemplate: public SharedTangibleObjectTemplate {
protected:

	String animation;

public:
	LiveSampleTemplate() {
		animation = "";
	}

	~LiveSampleTemplate() {

	}

	void readObject(LuaObject* templateData) {
		SharedTangibleObjectTemplate::readObject(templateData);
		animation = templateData->getStringField("animation");

	}

	String getAnimation() {
		return animation;
	}
};
