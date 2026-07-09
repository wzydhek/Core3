#include "CampDespawnTask.h"

CampDespawnTask::CampDespawnTask(CampSiteActiveArea* camp) {
	campSite = camp;
}

void CampDespawnTask::run() {
	if (campSite == nullptr)
		return;

	ZoneServer* zoneServer = campSite->getZoneServer();

	if (zoneServer != nullptr && zoneServer->isServerLoading()) {
		schedule(1000);

		return;
	}

	Locker locker(campSite);
	campSite->despawnCamp();
}