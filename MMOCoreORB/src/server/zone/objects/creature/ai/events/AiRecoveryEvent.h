/*
 * AiRecoveryEvent.h
 *
 *  Created on: 23/06/2010
 *  Author: victor
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

class AiRecoveryEvent : public Task {
	ManagedWeakReference<AiAgent*> agent;
	Time startTime;

public:
	AiRecoveryEvent(AiAgent* aiAgent);

	~AiRecoveryEvent();

	void run();

	void schedule(uint64 delay = 0);

	void clearAgentObject();
};

}
}
}
}
}
}

using namespace server::zone::objects::creature::events;
