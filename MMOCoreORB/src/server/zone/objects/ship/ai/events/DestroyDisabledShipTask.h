/*
 * DestroyDisabledShipTask.h
 *
 * Created on: 2026-02-21
 * Author: Hakry
 */

#pragma once

#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "server/zone/objects/ship/events/DestroyShipTask.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace events {

class DestroyDisabledShipTask : public Task {
	ManagedWeakReference<ShipAiAgent*> shipAgent;

public:
	DestroyDisabledShipTask(ShipAiAgent* agent);

	void run();

	void schedule(uint64 delay = 0);
};

} // namespace events
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::events;
