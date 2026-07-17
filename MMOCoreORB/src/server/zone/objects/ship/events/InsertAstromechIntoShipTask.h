/*
 * InsertAstromechIntoShipTask.h
 */

#pragma once

#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/objects/intangible/tasks/PetControlDeviceStoreTask.h"
#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/SpaceZone.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace events {

class InsertAstromechIntoShipTask : public Task, public Logger {
	ManagedWeakReference<ShipObject*> shipObj;

public:
	InsertAstromechIntoShipTask(ShipObject* shipObj);

	void run();
};

} // namespace events
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::events;
