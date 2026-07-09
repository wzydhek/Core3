/*
 * DroidTrapTask.h
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/player/PlayerManager.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidTrapTask : public Task {
	ManagedReference<CreatureObject* > droid;
	ManagedReference<CreatureObject* > player;
	ManagedReference<CreatureObject* > target;
	ManagedReference<Buff*> buff;
	StringIdChatParameter message;
	int damage;
	short pool;
	bool hit;
public:
	DroidTrapTask(CreatureObject* p, CreatureObject* t, CreatureObject* dr, Buff* b, const StringIdChatParameter& m, short po, int d, bool h);

	virtual ~DroidTrapTask();

	void run();
};

}
}
}
}
}

using namespace server::zone::objects::creature::events;
