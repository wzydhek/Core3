/*
 * DeedTemplate.h
 *
 *  Created on: May 8, 2010
 *      Author: crush
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class DeedTemplate : public SharedTangibleObjectTemplate {
	String generatedObjectTemplate;

public:
	DeedTemplate();

	~DeedTemplate();

	void readObject(LuaObject* templateData);

	const String& getGeneratedObjectTemplate() const;
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;