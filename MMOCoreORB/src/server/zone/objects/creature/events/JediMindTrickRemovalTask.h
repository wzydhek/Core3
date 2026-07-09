/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/managers/creature/PetManager.h"
#include "server/zone/objects/intangible/tasks/StorePetTask.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class JediMindTrickRemovalTask : public Task {
	ManagedWeakReference<CreatureObject*> pet;
	ManagedWeakReference<CreatureObject*> owner;

public:
	JediMindTrickRemovalTask(CreatureObject* pet, CreatureObject* owner);

	void run();
};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
