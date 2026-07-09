/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/managers/mission/spawnmaps/NpcSpawnPoint.h"
#include "server/zone/managers/mission/MissionManager.h"

namespace server {
namespace zone {
namespace managers {
namespace mission {
namespace spawnmaps {
namespace events {

class DespawnMissionNpcTask : public Task {
	WeakReference<MissionManager*> missionManager;
	WeakReference<NpcSpawnPoint*> npcSpawnPoint;

public:
	DespawnMissionNpcTask(MissionManager* missionManager, NpcSpawnPoint* npcSpawnPoint);

	void run();
};

} // namespace events
} // namespace spawnmaps
} // namespace mission
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::mission::spawnmaps::events;

