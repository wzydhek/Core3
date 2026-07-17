/*
 * SharedFactoryObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class SharedFactoryObjectTemplate : public SharedTangibleObjectTemplate {

public:
	SharedFactoryObjectTemplate();

	~SharedFactoryObjectTemplate();

	void readObject(LuaObject* templateData);

	void readObject(IffStream* iffStream);
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
