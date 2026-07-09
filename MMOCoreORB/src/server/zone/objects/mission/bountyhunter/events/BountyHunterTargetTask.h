/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/mission/MissionObject.h"
#include "server/zone/managers/mission/MissionManager.h"
#include "server/zone/managers/collision/PathFinderManager.h"
#include "server/zone/managers/planet/PlanetManager.h"
#include "server/zone/Zone.h"
#include "server/zone/objects/mission/BountyMissionObjective.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {
namespace bountyhunter {
namespace events {

class BountyHunterTargetTask: public Task, public Logger {
	ManagedWeakReference<MissionObject*> mission;
	ManagedWeakReference<BountyMissionObjective*> objective;
	ManagedWeakReference<CreatureObject*> player;

	Vector3 currentPosition;
	Vector3 destination;
	bool move, movedOffPlanet, movingToStarport, targetSpawned;
	String zoneName;

public:
	BountyHunterTargetTask(MissionObject* mission, CreatureObject* player, const String& zoneName);

	~BountyHunterTargetTask();

	void run();

	Vector3 getTargetPosition();

	const String& getTargetZoneName();

private:
	void updatePosition(CreatureObject* player);

	void updateToSpawnableTargetPosition();

	bool canSpawnTargetAt(const Vector3& position);
};

} // namespace events
} // namespace bountyhunter
} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission::bountyhunter::events;
