/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.
*/

#pragma once

#include "server/zone/objects/ship/PobShipObject.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace events {

class PobCellDotTask : public Task {
	ManagedWeakReference<PobShipObject*> weakShip;

public:
	PobCellDotTask(PobShipObject* ship);

	void run();

	void schedule(uint64 delay = 0);
};

} // namespace events
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
