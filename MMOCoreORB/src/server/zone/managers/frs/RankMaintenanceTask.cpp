#include "RankMaintenanceTask.h"
#include "server/zone/ZoneServer.h"

RankMaintenanceTask::RankMaintenanceTask(FrsManager* frs) {
	frsManager = frs;
}

void RankMaintenanceTask::run() {
	ManagedReference<FrsManager*> strongRef = frsManager.get();

	if (strongRef == nullptr)
		return;

	Locker locker(strongRef);

	strongRef->updateLastMaintenance();

	locker.release();

	Vector<uint64> playerList = strongRef->getFullPlayerList();

	if (playerList.size() == 0) {
		reschedule(strongRef->getMaintenanceInterval());
		return;
	}

	int playersPerTask = 10;
	int numTasks = ceil((float)playerList.size() / (float)playersPerTask);

	for (int i = 0; i < numTasks; i++) {
		Vector<uint64> taskList;

		for (int j = 0; j < playersPerTask; j++) {
			int curIndex = i * playersPerTask + j;

			if (curIndex >= playerList.size())
				break;

			taskList.add(playerList.get(curIndex));
		}

		Core::getTaskManager()->scheduleTask(
			[taskList, strongRef] {
				for (int i = 0; i < taskList.size(); i++) {
					ManagedReference<CreatureObject*> player = strongRef->getZoneServer()->getObject(taskList.get(i)).castTo<CreatureObject*>();

					if (player != nullptr) {
						Locker lock(player);
						strongRef->validatePlayerData(player, true);
						strongRef->deductMaintenanceXp(player);
					}
				}
			},
			"frsMaintenanceTask", (i + 1) * 500);
	}

	reschedule(strongRef->getMaintenanceInterval());
}