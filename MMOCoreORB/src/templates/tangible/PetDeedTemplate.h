/*
 * PetDeedTemplate.h
 *
 *  Created on: August 17, 2013
 *      Author: washu
 */

#pragma once

#include "templates/tangible/DeedTemplate.h"

namespace templates {
namespace tangible {

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

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
