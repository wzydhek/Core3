/*
 * ShipDeedTemplate.h
 *
 *  Created on: Jan. 1, 2023
 *  Author: H
 */

#pragma once

#include "templates/tangible/DeedTemplate.h"

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
