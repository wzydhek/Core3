/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/area/CampSiteActiveArea.h"

namespace server {
namespace zone {
namespace objects {
namespace area {
namespace events {

class CampAbandonTask: public Task {
	ManagedReference<CampSiteActiveArea*> campSite;


public:
	CampAbandonTask(CampSiteActiveArea* camp) {
		campSite = camp;
	}

	void run() {
		if (campSite == nullptr)
			return;

		Locker locker(campSite);
		campSite->abandonCamp();
	}
};


}
}
}
}
}
