
/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {
namespace crafting {
namespace events {

class UpdateToolCountdownTask : public Task {
	ManagedWeakReference<TangibleObject* > craftTool;
	ManagedWeakReference<CreatureObject* > player;
	int timeLeft;

public:
	UpdateToolCountdownTask(CreatureObject* pl, TangibleObject* tool, int time);

	void run();
};

} // namespace events
} // namespace crafting
} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions::crafting::events;
