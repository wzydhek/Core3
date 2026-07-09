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
	NavicomputerDeedTemplate();

	~NavicomputerDeedTemplate();

	void readObject(LuaObject* templateData);

	const String& getControlDeviceObjectTemplate() const;

	const String& getDatapadObjectTemplate() const;
};
