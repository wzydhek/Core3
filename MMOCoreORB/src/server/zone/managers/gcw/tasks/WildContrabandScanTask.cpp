#include "WildContrabandScanTask.h"

WildContrabandScanTask::WildContrabandScanTask(CreatureObject* player) {
	weakPlayer = player;
}

void WildContrabandScanTask::run() {
	ManagedReference<CreatureObject*> player = weakPlayer.get();

	if (player != nullptr) {
		ManagedReference<WildContrabandScanSession*> scanSession = player->getActiveSession(SessionFacadeType::WILDCONTRABANDSCAN).castTo<WildContrabandScanSession*>();
		if (scanSession != nullptr) {
			scanSession->runWildContrabandScan();
		}
	}
}