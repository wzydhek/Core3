/*
	Copyright <SWGEmu>
	See file COPYING for copying conditions.
*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/packets/scene/PlayClientEffectLocMessage.h"
#include "server/zone/Zone.h"
#include "server/zone/managers/planet/PlanetManager.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/managers/structure/StructureManager.h"
#include "server/zone/objects/structure/StructureObject.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/CloseObjectsVector.h"
#include "server/zone/objects/mission/BountyMissionObjective.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {
namespace bountyhunter {
namespace events {

class CallArakydTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> player;
	ManagedWeakReference<BountyMissionObjective*> objective;
	int time;
	Vector3 droidPosition;
	ManagedReference<AiAgent*> droid;

public:
	CallArakydTask(CreatureObject* player, BountyMissionObjective* objective);

	~CallArakydTask();

	void run();

	Vector3 getLandingCoordinates(CreatureObject* player);
};

} // namespace events
} // namespace bountyhunter
} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission::bountyhunter::events;
