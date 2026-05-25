/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/area/CampSiteActiveArea.h"
#include "server/zone/ZoneServer.h"

namespace server {
namespace zone {
namespace objects {
namespace area {
namespace events {

class CampDespawnTask: public Task {
	ManagedReference<CampSiteActiveArea*> campSite;

public:
	CampDespawnTask(CampSiteActiveArea* camp) {
		campSite = camp;
	}

	void run() {
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
};


}
}
}
}
}
