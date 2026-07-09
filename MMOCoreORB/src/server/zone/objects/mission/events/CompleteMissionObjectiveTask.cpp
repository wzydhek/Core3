#include "CompleteMissionObjectiveTask.h"
#include "server/zone/objects/creature/CreatureObject.h"

CompleteMissionObjectiveTask::CompleteMissionObjectiveTask(MissionObjective* missionObjective) {
	objective = missionObjective;
}

void CompleteMissionObjectiveTask::run() {
	Locker locker(objective);

	if (objective->getPlayerOwner() == nullptr)
		return;

	objective->awardReward();

	objective->awardFactionPoints();

	objective->removeMissionFromPlayer();
}