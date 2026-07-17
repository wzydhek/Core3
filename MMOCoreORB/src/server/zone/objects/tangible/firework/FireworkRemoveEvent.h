/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/staticobject/StaticObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace firework {

class FireworkRemoveEvent : public Task {
	ManagedReference<StaticObject*> firework;
	ManagedReference<CreatureObject*> player;

public:
	FireworkRemoveEvent(CreatureObject* player, StaticObject* firework);

	void run();
};

} // namespace firework
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::firework;
