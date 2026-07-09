/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/creature/ai/Creature.h"
#include "server/zone/objects/tangible/components/droid/DroidHarvestModuleDataComponent.h"
#include "server/zone/managers/creature/CreatureManager.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidHarvestTask : public Task {
	Reference<DroidHarvestModuleDataComponent*> module;
	ManagedWeakReference<CreatureObject*> creature;

public:
	DroidHarvestTask(DroidHarvestModuleDataComponent* module, CreatureObject* creo);

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
