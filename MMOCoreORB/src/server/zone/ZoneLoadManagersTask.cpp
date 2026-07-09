#include "ZoneLoadManagersTask.h"

ZoneLoadManagersTask::ZoneLoadManagersTask(ZoneServer* server, Zone* zone) {
	this->zone = zone;
	zoneServer = server;
}

void ZoneLoadManagersTask::run() {
	if (zone == nullptr)
		return;

	if (zone->hasManagersStarted())
		return;

	zone->startManagers();
}