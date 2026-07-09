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

class DroidPowerTask : public Task {

	ManagedWeakReference<DroidObject*> droid;

public:
	DroidPowerTask(DroidObject* droid);

	void run();
};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
