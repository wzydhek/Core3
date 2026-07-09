#include "RemoveNoSpawnAreaTask.h"
#include "server/zone/ZoneServer.h"

RemoveNoSpawnAreaTask::RemoveNoSpawnAreaTask(ActiveArea* camp) {
	area = camp;
}

void RemoveNoSpawnAreaTask::run() {
	ManagedReference<ActiveArea*> strongArea = area.get();

	if (strongArea == nullptr)
		return;

	ZoneServer* zoneServer = strongArea->getZoneServer();

	if (zoneServer == nullptr || zoneServer->isServerShuttingDown())
		return;

	Locker locker(strongArea);

	strongArea->destroyObjectFromWorld(true);
}