/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/tangible/TangibleObject.h"
#include "templates/creature/VehicleObjectTemplate.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class VehicleDecayTask : public Task {
	ManagedWeakReference<TangibleObject*> vehicleObj;
	bool initialDecay;

public:
	VehicleDecayTask(TangibleObject* veh);

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
