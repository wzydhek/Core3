/*
 * CamoKitTemplate.h
 *
 *  Created on: Feb 11, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class CamoKitTemplate : public SharedTangibleObjectTemplate {
	String effectiveZone;

public:
	CamoKitTemplate();

	~CamoKitTemplate();

	void readObject(LuaObject* templateData);

	String& getEffectiveZone();

    bool isCamoKitTemplate();

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
