/*
 * AwardRewardTask.h
 *
 *  Created on: 13/06/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/mission/MissionObjective.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {
namespace events {

class CompleteMissionObjectiveTask : public Task {
	ManagedReference<MissionObjective*> objective;

public:
	CompleteMissionObjectiveTask(MissionObjective* missionObjective);

	void run();
};

} // namespace events
} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission::events;
