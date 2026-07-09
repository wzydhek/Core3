/*
 * SharedBattlefieldMarkerObjectTemplate.h
 *
 *  Created on: 05/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class SharedBattlefieldMarkerObjectTemplate : public SharedTangibleObjectTemplate {

public:
	SharedBattlefieldMarkerObjectTemplate();

	~SharedBattlefieldMarkerObjectTemplate();

	void readObject(LuaObject* templateData);

	void readObject(IffStream* iffStream);

};
