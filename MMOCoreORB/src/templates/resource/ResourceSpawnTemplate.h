/*
 * SharedResourceContainerObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: kyle
 */

#pragma once

#include "templates/tangible/SharedResourceContainerObjectTemplate.h"

namespace templates {
namespace resource {

class ResourceSpawnTemplate : public SharedResourceContainerObjectTemplate {
private:

public:
	ResourceSpawnTemplate();

	~ResourceSpawnTemplate();

	void readObject(LuaObject* templateData);
};

} // namespace resource
} // namespace templates

using namespace templates::resource;
