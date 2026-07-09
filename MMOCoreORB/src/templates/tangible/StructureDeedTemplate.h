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
	StructureDeedTemplate();

	void readObject(LuaObject* obj);

	const String& getStructurePlacementComponent();
};
