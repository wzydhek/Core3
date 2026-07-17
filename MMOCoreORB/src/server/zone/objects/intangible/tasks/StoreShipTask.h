/*
 * StoreShipTask.h
 */

#pragma once

#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/intangible/ShipControlDevice.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/objects/ship/PobShipObject.h"
#include "templates/params/creature/PlayerArrangement.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/intangible/tasks/PetControlDeviceStoreTask.h"

// #define DEBUG_SHIP_STORE

namespace server {
namespace zone {
namespace objects {
namespace intangible {
namespace tasks {

class StoreShipTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> play;
	ManagedWeakReference<ShipControlDevice*> shipDev;
	String zoneName;
	Vector3 coordinates;

public:
	StoreShipTask(CreatureObject* creo, ShipControlDevice* controlDevice, String zName, Vector3 coords);

	void run();

	bool removeDroid(ShipObject* ship, CreatureObject* player);
};

} // namespace tasks
} // namespace intangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::intangible::tasks;
