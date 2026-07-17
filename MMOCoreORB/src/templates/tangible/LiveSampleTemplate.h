/*
 * LiveSampleTemplate.h
 *
 *  Created on: March 16, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class LiveSampleTemplate: public SharedTangibleObjectTemplate {
protected:

	String animation;

public:
	LiveSampleTemplate();

	~LiveSampleTemplate();

	void readObject(LuaObject* templateData);

	String getAnimation();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
