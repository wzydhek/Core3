/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
	namespace mission {
		class MissionObject;
	}

	namespace player {
		class PlayerObject;
	}

namespace group {
	class GroupObject;

namespace tasks {

class UpdateNearestMissionForGroupTask : public Task, public Logger {
	WeakReference<GroupObject*> groupRef;
	unsigned int planetCRC;

public:
	UpdateNearestMissionForGroupTask(GroupObject* group, const unsigned int planetCRC);
	void run();

private:
	float calculateManhattanDistanceToMission(const Vector3& position, server::zone::objects::mission::MissionObject* mission);

	void setPlayersNearestMissionForGroupWaypoint(server::zone::objects::player::PlayerObject* ghost, server::zone::objects::mission::MissionObject* nearestMissionForGroup);
};

} // namespace tasks
} // namespace group
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::group::tasks;
