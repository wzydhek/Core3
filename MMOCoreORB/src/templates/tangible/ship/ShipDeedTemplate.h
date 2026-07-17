/*
 * ShipDeedTemplate.h
 *
 *  Created on: Jan. 1, 2023
 *  Author: H
 */

#pragma once

#include "templates/tangible/DeedTemplate.h"

namespace templates {
namespace tangible {
namespace ship {

class ShipDeedTemplate : public DeedTemplate {
	String shipControlDevice;
	int shipType;

public:
	ShipDeedTemplate();

	~ShipDeedTemplate();

	void readObject(LuaObject* templateData);

	const String& getShipControlDeviceTemplate();

	int getShipType();

	bool isShipDeedTemplate();
};

} // namespace ship
} // namespace tangible
} // namespace templates

using namespace templates::tangible::ship;
