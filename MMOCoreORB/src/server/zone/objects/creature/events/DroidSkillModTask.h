/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/ai/DroidObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidSkillModTask : public Task {

	ManagedWeakReference<DroidObject*> droid;
	ManagedWeakReference<CreatureObject*> owner;

public:
	DroidSkillModTask(DroidObject* droid, CreatureObject* owner);

	void run();
};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
