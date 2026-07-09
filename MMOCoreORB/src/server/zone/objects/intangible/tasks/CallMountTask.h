/*
 * CallMountTask.h
 *
 *  Created on: 1/22/2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/intangible/ControlDevice.h"
#include "server/zone/objects/intangible/VehicleControlDevice.h"

class CallMountTask : public Task {
	ManagedReference<CreatureObject*> player;
	ManagedReference<VehicleControlDevice*> device;
	String taskName;

public:
	CallMountTask(VehicleControlDevice* controlDevice, CreatureObject* creo, const String& task);

	void run();
};
