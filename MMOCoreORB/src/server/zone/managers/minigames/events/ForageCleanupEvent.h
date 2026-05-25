/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/ZoneProcessServer.h"

namespace server {
namespace zone {
namespace managers {
namespace minigames {
namespace events {

class ForageCleanupEvent : public Task {

public:
	ForageCleanupEvent(const String& name, ZoneProcessServer* zoneServer);

	void run();

	String playerName;
	ManagedReference<ZoneProcessServer*> zoneServer;

};

}
}
}
}
}

using namespace server::zone::managers::minigames::events;
