/*
 * DroidComponentTemplate.h
 *
 *  Created on: Aug 21, 2014
 *      Author: washu
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class DroidComponentTemplate : public SharedTangibleObjectTemplate {

public:
	DroidComponentTemplate();

	~DroidComponentTemplate();

	void readObject(LuaObject* templateData);

	bool isDroidComponentTemplate();

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;