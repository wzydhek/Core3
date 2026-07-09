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
	LiveSampleTemplate();

	~LiveSampleTemplate();

	void readObject(LuaObject* templateData);

	String getAnimation();
};
