#include "CheckWildContrabandScanTask.h"

CheckWildContrabandScanTask::CheckWildContrabandScanTask(GCWManager* manager) {
	gcwManager = manager;
}

void CheckWildContrabandScanTask::run() {
	ManagedReference<GCWManager*> strongRef = gcwManager.get();

	if (strongRef == nullptr) {
		return;
	}

	ZoneServer* server = strongRef->getZone()->getZoneServer();

	if (server == nullptr || server->isServerShuttingDown())
		return;

	if (!server->isServerOnline()) {
		uint64 delay = strongRef->getWildScanInterval() + System::random(600000);

		schedule(delay);
		return;
	}

	strongRef->performCheckWildContrabandScanTask();
}