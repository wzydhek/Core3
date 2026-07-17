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

namespace server {
namespace zone {
namespace objects {
namespace intangible {
namespace tasks {

class CallMountTask : public Task {
	ManagedReference<CreatureObject*> player;
	ManagedReference<VehicleControlDevice*> device;
	String taskName;

public:
	CallMountTask(VehicleControlDevice* controlDevice, CreatureObject* creo, const String& task);

	void run();
};

} // namespace tasks
} // namespace intangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::intangible::tasks;
