/*
 * LaunchShipTask.h
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/intangible/ShipControlDevice.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/managers/planet/PlanetManager.h"
#include "server/zone/objects/ship/events/InsertPilotIntoShipTask.h"
#include "server/zone/objects/ship/events/InsertGroupMemberIntoShipTask.h"
#include "server/zone/objects/ship/events/InsertAstromechIntoShipTask.h"
#include "templates/params/creature/PlayerArrangement.h"

namespace server {
namespace zone {
namespace objects {
namespace intangible {
namespace tasks {

class LaunchShipTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> play;
	ManagedWeakReference<ShipControlDevice*> shipDev;
	Vector<uint64> groupMembers;
	String chosenZone;

public:
	LaunchShipTask(CreatureObject* creo, ShipControlDevice* controlDevice, Vector<uint64> group);

	LaunchShipTask(CreatureObject* creo, ShipControlDevice* controlDevice, Vector<uint64> group, String zoneName);

	void run();

	void handleDroid(CreatureObject* player, ShipObject* ship, ShipControlDevice* shipControlDevice);

};

} // namespace tasks
} // namespace intangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::intangible::tasks;
