/*
 * AiBehaviorEvent.h
 *
 *  Created on: 10/07/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/managers/creature/AiMap.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace events {

class AiBehaviorEvent : public Task {
	ManagedWeakReference<AiAgent*> creature;
	bool hasFollowObject;
	bool isRetreating;

public:
	AiBehaviorEvent(AiAgent* pl);

	~AiBehaviorEvent();

	void run();

	void schedule(uint64 delay = 0);

	bool cancel();

	void clearCreatureObject();

};

}
}
}
}
}
}

using namespace server::zone::objects::creature::events;
