/*
 * VehicleCustomKitTemplate.h
 *
 *  Created on: May 1, 2013
 *      Author: trick77
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class VehicleCustomKitTemplate : public SharedTangibleObjectTemplate {

public:
	VehicleCustomKitTemplate();

	~VehicleCustomKitTemplate();

	void readObject(LuaObject* templateData);

	bool isVehicleCustomKitTemplate();

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
