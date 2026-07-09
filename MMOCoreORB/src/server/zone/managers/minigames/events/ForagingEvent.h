/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/minigames/ForageManager.h"

namespace server {
namespace zone {
namespace managers {
namespace minigames {
namespace events {

class ForagingEvent : public Task {

	ManagedReference<CreatureObject*> player;
	int forageType;
	float forageX;
	float forageY;
	String zoneName;

public:
	ForagingEvent(CreatureObject* player, int type, float playerX, float playerY, const String& planet);

	void run();
};

}
}
}
}
}

using namespace server::zone::managers::minigames::events;
