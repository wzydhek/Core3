#include "CheckGCWTask.h"

CheckGCWTask::CheckGCWTask(GCWManager* manager) {
	gcwManager = manager;

	setCustomTaskQueue("slowQueue");
}

void CheckGCWTask::run() {
	ManagedReference<GCWManager*> strongRef = gcwManager.get();

	if (strongRef == nullptr) {
		return;
	}

	ZoneServer* server = strongRef->getZone()->getZoneServer();

	if (server == nullptr || server->isServerShuttingDown())
		return;

	if (!server->isServerOnline()) {
		schedule((60 + System::random(30)) * 1000);
		return;
	}

	strongRef->performGCWTasks();
}