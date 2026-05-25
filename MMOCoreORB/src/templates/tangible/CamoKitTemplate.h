/*
 * CamoKitTemplate.h
 *
 *  Created on: Feb 11, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class CamoKitTemplate : public SharedTangibleObjectTemplate {
	String effectiveZone;

public:
	CamoKitTemplate() {
		effectiveZone = "";
	}

	~CamoKitTemplate() {

	}

	void readObject(LuaObject* templateData) {
		SharedTangibleObjectTemplate::readObject(templateData);

		effectiveZone = templateData->getStringField("effectiveZone");
}

	inline String& getEffectiveZone() {
		return effectiveZone;
	}

    bool isCamoKitTemplate() {
    	return true;
    }

};
