/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/ZoneProcessServer.h"
#include "server/zone/managers/minigames/FishingManager.h"

namespace server {
namespace zone {
namespace managers {
namespace minigames {
namespace events {

class FishingEvent : public Task {
	ManagedWeakReference<CreatureObject*> weakPlayer;
	int fishingState;

public:
	FishingEvent(CreatureObject* player, int state);

	void run();

	void clearPlayerFishing(CreatureObject* player);
};

} // namespace events
} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames::events;
