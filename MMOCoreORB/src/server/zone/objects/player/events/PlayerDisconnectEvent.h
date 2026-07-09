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

class PlayerDisconnectEvent : public Task {
	ManagedWeakReference<PlayerObject*> player;
	bool isSafeArea;
public:
	PlayerDisconnectEvent(PlayerObject* pl, bool isSafe);

	void run();

};

}
}
}
}
}

using namespace server::zone::objects::player::events;
