/*
 * AwardRewardTask.h
 *
 *  Created on: 13/06/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/mission/MissionObjective.h"

class CompleteMissionObjectiveTask : public Task {
	ManagedReference<MissionObjective*> objective;

public:
	CompleteMissionObjectiveTask(MissionObjective* missionObjective);

	void run();
};
