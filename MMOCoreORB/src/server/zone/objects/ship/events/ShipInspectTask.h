/*
 *	Copyright <SWGEmu>
 *	See file COPYING for copying conditions.
 *
 *	ShipInspectTask.h
 *
 *	Created on: 2025-10-14
 *	Author: Hakry
 */

#pragma once

#include "server/zone/objects/ship/ShipObject.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace events {

class ShipInspectTask: public Task, public Logger {

protected:
	ManagedWeakReference<CreatureObject*> weakPlayer;
	ManagedWeakReference<ShipObject*> weakTargetShip;

public:
	ShipInspectTask(CreatureObject* player, ShipObject* targetShip);

	void run();
};

} // namespace events
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::events;
