#include "ContrabandScanTask.h"

ContrabandScanTask::ContrabandScanTask(CreatureObject* player) {
	weakPlayer = player;
}

void ContrabandScanTask::run() {
	ManagedReference<CreatureObject*> player = weakPlayer.get();

	if (player != nullptr) {
		Locker locker(player);
		ManagedReference<ContrabandScanSession*> scanSession = player->getActiveSession(SessionFacadeType::CONTRABANDSCAN).castTo<ContrabandScanSession*>();
		if (scanSession != nullptr) {
			scanSession->runContrabandScan();
		}
	}
}