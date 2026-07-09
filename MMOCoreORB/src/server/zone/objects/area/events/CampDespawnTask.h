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
	CampDespawnTask(CampSiteActiveArea* camp);

	void run();
};


}
}
}
}
}

using namespace server::zone::objects::area::events;
