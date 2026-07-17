/*
 * SpaceZoneLoadManagersTask.h
 *
 *  Created on: Nov 18, 2010
 *      Author: oru
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/SpaceZone.h"

namespace server {
namespace zone {

class SpaceZoneLoadManagersTask : public Task {
	ManagedReference<ZoneServer*> zoneServer;
	ManagedReference<SpaceZone*> zone;
public:
	SpaceZoneLoadManagersTask(ZoneServer* server, SpaceZone* zone);

	void run();
};

} // namespace zone
} // namespace server

using namespace server::zone;
