/*
 * SharedBattlefieldMarkerObjectTemplate.h
 *
 *  Created on: 05/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class SharedBattlefieldMarkerObjectTemplate : public SharedTangibleObjectTemplate {

public:
	SharedBattlefieldMarkerObjectTemplate();

	~SharedBattlefieldMarkerObjectTemplate();

	void readObject(LuaObject* templateData);

	void readObject(IffStream* iffStream);

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
