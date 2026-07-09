/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/tangible/components/droid/DroidPlaybackModuleDataComponent.h"
#include "server/zone/packets/creature/CreatureObjectDeltaMessage6.h"
#include "server/zone/managers/skill/Performance.h"
#include "server/zone/managers/skill/PerformanceManager.h"
#include "server/zone/managers/skill/SkillManager.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidPlaybackTask : public Task {

	Reference<DroidPlaybackModuleDataComponent*> module;
	bool playing;
public:
	DroidPlaybackTask(DroidPlaybackModuleDataComponent* module);

	void run();
};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
