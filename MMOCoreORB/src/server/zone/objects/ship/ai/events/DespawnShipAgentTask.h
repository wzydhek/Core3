/*
 * DespawnShipAgentTask.h
 *
 * Created on: 2024-10-25
 * Author: Hakry
 */

#pragma once

#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace events {

class DespawnShipAgentTask : public Task {
	ManagedReference<ShipAiAgent*> shipAgent;

public:
	DespawnShipAgentTask(ShipAiAgent* agent);

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
