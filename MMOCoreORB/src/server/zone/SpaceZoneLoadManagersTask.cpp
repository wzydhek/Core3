#include "SpaceZoneLoadManagersTask.h"

SpaceZoneLoadManagersTask::SpaceZoneLoadManagersTask(ZoneServer* server, SpaceZone* zone) {
	this->zone = zone;
	zoneServer = server;
}

void SpaceZoneLoadManagersTask::run() {
	if (zone == nullptr)
		return;

	if (zone->hasManagersStarted())
		return;

	zone->startManagers();
}