/*
 * NavicomputerDeedTemplate.h
 *
 *  Created on: March 7, 2025
 *      Author: Halyn
 */

#pragma once

#include "templates/tangible/DeedTemplate.h"

class NavicomputerDeedTemplate : public DeedTemplate {
	String controlDeviceObjectTemplate;
	String datapadObjectTemplate;

public:
	NavicomputerDeedTemplate() {

	}

	~NavicomputerDeedTemplate() {

	}

	void readObject(LuaObject* templateData) {
		DeedTemplate::readObject(templateData);
		controlDeviceObjectTemplate = templateData->getStringField("controlDeviceObjectTemplate");
		datapadObjectTemplate = templateData->getStringField("datapadObjectTemplate");
	}

	const String& getControlDeviceObjectTemplate() const {
		return controlDeviceObjectTemplate;
	}

	const String& getDatapadObjectTemplate() const {
		return datapadObjectTemplate;
	}
};
