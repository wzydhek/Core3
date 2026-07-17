/*
 * SharedStaticObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedObjectTemplate.h"
#include "building/SharedBuildingObjectTemplate.h"

namespace templates {

class SharedStaticObjectTemplate : public SharedBuildingObjectTemplate {
protected:


public:
	SharedStaticObjectTemplate();

	~SharedStaticObjectTemplate();

	void readObject(LuaObject* templateData);

	void readObject(IffStream* iffStream);

};

} // namespace templates

using namespace templates;