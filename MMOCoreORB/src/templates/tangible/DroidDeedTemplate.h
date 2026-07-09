/*
 * DroidDeedTemplate.h
 *
 *  Created on: October 23, 2013
 *      Author: Klivian
 */

#pragma once

#include "templates/tangible/DeedTemplate.h"

class DroidDeedTemplate : public DeedTemplate {
	String controlDeviceObjectTemplate;
	String mobileTemplate;
	int species;

public:
	DroidDeedTemplate();

	~DroidDeedTemplate();

	void readObject(LuaObject* templateData);

	const String& getControlDeviceObjectTemplate() const;

	const String& getMobileTemplate() const;

	int getSpecies() const;
};
