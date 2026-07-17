/*
 * RemoveNoSpawnAreaTask.h
 *
 *  Created on: 16/05/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/area/ActiveArea.h"

namespace server {
namespace zone {
namespace objects {
namespace area {
namespace events {

class RemoveNoSpawnAreaTask : public Task {
	ManagedWeakReference<ActiveArea*> area;

public:
	RemoveNoSpawnAreaTask(ActiveArea* camp);

	void run();
};

} // namespace events
} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area::events;
