/*
 * ZoneLoadManagersTask.h
 *
 *  Created on: Nov 18, 2010
 *      Author: oru
 */
#pragma once

#include "engine/engine.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {

class ZoneLoadManagersTask : public Task {
	ManagedReference<ZoneServer*> zoneServer;
	ManagedReference<Zone*> zone;
public:
	ZoneLoadManagersTask(ZoneServer* server, Zone* zone);

	void run();
};

} // namespace zone
} // namespace server

using namespace server::zone;
