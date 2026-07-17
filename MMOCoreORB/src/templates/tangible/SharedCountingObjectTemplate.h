/*
 * SharedCountingObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class SharedCountingObjectTemplate : public SharedTangibleObjectTemplate {

public:
	SharedCountingObjectTemplate();

	~SharedCountingObjectTemplate();

	void readObject(LuaObject* templateData);

	void readObject(IffStream* iffStream);
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
