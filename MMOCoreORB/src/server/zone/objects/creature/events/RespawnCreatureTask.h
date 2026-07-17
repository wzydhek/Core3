/*
 * RespawnCreatureTask.h
 *
 *  Created on: 03/08/2010
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

class RespawnCreatureTask : public Task {
	ManagedReference<AiAgent*> creature;
	Zone* zone;
	int level;

public:
	RespawnCreatureTask(AiAgent* cr, Zone* zn, int level);

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
