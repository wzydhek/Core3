/*
 * VehicleCustomKitTemplate.h
 *
 *  Created on: May 1, 2013
 *      Author: trick77
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class VehicleCustomKitTemplate : public SharedTangibleObjectTemplate {

public:
	VehicleCustomKitTemplate() {

	}

	~VehicleCustomKitTemplate() {

	}

	void readObject(LuaObject* templateData) {
		SharedTangibleObjectTemplate::readObject(templateData);

    }

	bool isVehicleCustomKitTemplate() {
		return true;
	}

};
