/*
 * PetDeedTemplate.h
 *
 *  Created on: August 17, 2013
 *      Author: washu
 */

#pragma once

#include "templates/tangible/DeedTemplate.h"

class PetDeedTemplate : public DeedTemplate {
private:
	String controlDeviceObjectTemplate;
	String mobileTemplate;

public:
	PetDeedTemplate();

	~PetDeedTemplate();

	void readObject(LuaObject* templateData);

	String getControlDeviceObjectTemplate();

	String getMobileTemplate();

};
