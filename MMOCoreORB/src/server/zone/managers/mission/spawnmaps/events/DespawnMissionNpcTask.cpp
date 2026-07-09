#include "DespawnMissionNpcTask.h"

DespawnMissionNpcTask::DespawnMissionNpcTask(MissionManager* missionManager, NpcSpawnPoint* npcSpawnPoint) {
	this->missionManager = missionManager;
	this->npcSpawnPoint = npcSpawnPoint;
}

void DespawnMissionNpcTask::run() {
	auto strongReferenceSpawnPoint = npcSpawnPoint.get();
	auto strongReferenceManager = missionManager.get();

	if (strongReferenceSpawnPoint && strongReferenceManager) {
		strongReferenceManager->despawnMissionNpc(strongReferenceSpawnPoint);
	}
}