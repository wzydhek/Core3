/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/firework/FireworkObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace firework {

class FireworkLaunchEvent : public Task {
	ManagedWeakReference<FireworkObject*> firework;
	ManagedWeakReference<CreatureObject*> player;
	int removeDelay;

public:
	FireworkLaunchEvent(CreatureObject* player, FireworkObject* firework, int removeDelay);

	void run();
};

} // namespace firework
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::firework;
