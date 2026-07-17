/*
 * DespawnCreatureTask.h
 *
 *  Created on: 12/07/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DespawnCreatureTask : public Task {
	ManagedReference<AiAgent*> agent;

public:
	DespawnCreatureTask(AiAgent* creature);

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
