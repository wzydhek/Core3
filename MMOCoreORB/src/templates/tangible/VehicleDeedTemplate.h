/*
 * VehicleDeedTemplate.h
 *
 *  Created on: Oct 4, 2010
 *      Author: kyle
 */

#pragma once

#include "templates/tangible/DeedTemplate.h"

class VehicleDeedTemplate : public DeedTemplate {
private:
	String controlDeviceObjectTemplate;

public:
	VehicleDeedTemplate();

	~VehicleDeedTemplate();

	void readObject(LuaObject* templateData);

	String getControlDeviceObjectTemplate();
};
