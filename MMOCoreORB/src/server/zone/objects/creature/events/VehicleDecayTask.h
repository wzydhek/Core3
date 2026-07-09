/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/tangible/TangibleObject.h"
#include "templates/creature/VehicleObjectTemplate.h"

class VehicleDecayTask : public Task {
	ManagedWeakReference<TangibleObject*> vehicleObj;
	bool initialDecay;

public:
	VehicleDecayTask(TangibleObject* veh);

	void run();
};
