/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class SpiceDownerAnimationTask : public Task {

	ManagedReference<CreatureObject*> player;
	uint32 debuffCRC;

public:
	SpiceDownerAnimationTask(CreatureObject* player, uint32 debuffCRC);

	void run();
};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
