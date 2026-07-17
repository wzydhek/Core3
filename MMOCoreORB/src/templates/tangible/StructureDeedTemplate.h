/*
 * StructureDeedTemplate.h
 *
 *  Created on: Feb 5, 2012
 *      Author: xyborn
 */

#pragma once

#include "templates/tangible/DeedTemplate.h"

namespace templates {
namespace tangible {

class StructureDeedTemplate : public DeedTemplate {
	String placementComponent;

public:
	StructureDeedTemplate();

	void readObject(LuaObject* obj);

	const String& getStructurePlacementComponent();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
