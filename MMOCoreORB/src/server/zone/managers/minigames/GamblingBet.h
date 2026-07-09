/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace managers {
namespace minigames {

class GamblingBet : public Object {
	ManagedWeakReference<CreatureObject*> player;
	int amount;
	String target;

public:
	GamblingBet(CreatureObject* pl, int bet, String betTarget);

	GamblingBet(CreatureObject* pl, int bet);

	int getAmount() const;

	const String& getTarget() const;

	CreatureObject* getPlayer();

};

}
}
}
}

using namespace server::zone::managers::minigames;

