/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sessions/ProposeUnitySession.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class ProposeUnityExpiredTask : public Task {

	ManagedReference<CreatureObject*> player;

public:
	ProposeUnityExpiredTask(CreatureObject* player);

	void run();
};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
