/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class ForceRegenerationEvent : public Task {
	ManagedWeakReference<PlayerObject*> weakGhost;

public:
	ForceRegenerationEvent(PlayerObject* ghost);

	void run();
};

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;
