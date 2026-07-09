/*
 * DespawnAiShipOnNoPlayersInRange.h
 */

#pragma once

#include "server/zone/objects/ship/ai/ShipAiAgent.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace events {

class DespawnAiShipOnNoPlayersInRange : public Task {
	ManagedWeakReference<ShipAiAgent*> ship;

public:
	DespawnAiShipOnNoPlayersInRange(ShipAiAgent* shipO);

	void run();
};

} // namespace events
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::events;
