/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/tangible/components/droid/DroidEffectsModuleDataComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidEffectsTask : public Task, public Logger {

	Reference<DroidEffectsModuleDataComponent*> module;

public:
	DroidEffectsTask(DroidEffectsModuleDataComponent* module);

	void run();

};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
