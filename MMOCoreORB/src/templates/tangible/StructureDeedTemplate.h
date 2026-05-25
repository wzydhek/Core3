/*
 * StructureDeedTemplate.h
 *
 *  Created on: Feb 5, 2012
 *      Author: xyborn
 */

#pragma once

#include "templates/tangible/DeedTemplate.h"

class StructureDeedTemplate : public DeedTemplate {
	String placementComponent;

public:
	StructureDeedTemplate() {

	}

	void readObject(LuaObject* obj) {
		DeedTemplate::readObject(obj);

		placementComponent = obj->getStringField("placeStructureComponent");
	}

	inline const String& getStructurePlacementComponent() {
		return placementComponent;
	}
};
