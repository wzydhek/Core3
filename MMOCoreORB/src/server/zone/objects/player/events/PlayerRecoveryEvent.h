/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class PlayerRecoveryEvent : public Task {
	ManagedWeakReference<PlayerObject*> weakGhost;
	Time startTime;

public:
	PlayerRecoveryEvent(PlayerObject* ghost);

	~PlayerRecoveryEvent();

	void run();

	void schedule(uint64 delay = 0);
};

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;
