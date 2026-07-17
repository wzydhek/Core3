/*
 * ShipAiBehaviorEvent.h
 */

#pragma once

#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "server/zone/managers/space/SpaceAiMap.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace events {

class ShipAiBehaviorEvent : public Task {
	ManagedWeakReference<ShipAiAgent*> agent;
	bool hasFollowObject;
	bool isRetreating;

public:
	ShipAiBehaviorEvent(ShipAiAgent* pl);

	~ShipAiBehaviorEvent();

	void run();

	void schedule(uint64 delay = 0);

	bool cancel();

	void clearShipAgentObject();
};

} // namespace events
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::events;
