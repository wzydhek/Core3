/*
 * CampKitTemplate.h
 *
 *  Created on: 05/11/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class CampKitTemplate : public SharedTangibleObjectTemplate {
	String spawnObjectTemplate;

public:
	void readObject(LuaObject* templateData);

	const String& getSpawnObjectTemplate();

	bool isCampKitTemplate();
};
