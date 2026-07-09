/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/tangible/components/droid/DroidDetonationModuleDataComponent.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/collision/CollisionManager.h"
#include "server/zone/managers/combat/CombatManager.h"
#include "server/zone/packets/object/PlayClientEffectObjectMessage.h"
#include "server/zone/packets/scene/PlayClientEffectLocMessage.h"
#include "server/zone/Zone.h"
#include "server/zone/objects/intangible/PetControlDevice.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidDetonationTask : public Task, public Logger {
private:
	Reference<DroidDetonationModuleDataComponent*> module;
	ManagedReference<CreatureObject*> player;
	int detonationStep;

public:
	DroidDetonationTask(DroidDetonationModuleDataComponent* module, CreatureObject* player);

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
