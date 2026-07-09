/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace events {

class ShipRecoveryEvent : public Task {
	ManagedWeakReference<ShipObject*> weakShip;

public:
	ShipRecoveryEvent(ShipObject* shipObj);

	void run();

	void schedule(uint64 delay = 0);
};

} // namespace events
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::events;
