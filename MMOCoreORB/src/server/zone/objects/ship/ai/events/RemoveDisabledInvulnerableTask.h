/*
 * RemoveDisabledInvulnerableTask.h
 */

#pragma once

#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "templates/params/ship/ShipFlag.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace events {

class RemoveDisabledInvulnerableTask : public Task {
	ManagedWeakReference<ShipAiAgent*> ship;

public:
	RemoveDisabledInvulnerableTask(ShipAiAgent* shipO);

	void run();
};

} // namespace events
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::events;
