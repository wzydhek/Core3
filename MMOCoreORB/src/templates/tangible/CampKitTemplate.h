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
	void readObject(LuaObject* templateData) {
		SharedTangibleObjectTemplate::readObject(templateData);

		spawnObjectTemplate = templateData->getStringField("spawnObjectTemplate");
	}

	inline const String& getSpawnObjectTemplate() {
		return spawnObjectTemplate;
	}

	bool isCampKitTemplate() {
		return true;
	}
};
