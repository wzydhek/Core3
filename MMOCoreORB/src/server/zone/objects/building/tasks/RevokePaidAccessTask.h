/*
 * RevokePaidAccessTask.h
 *
 *  Created on: June 2, 2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/building/BuildingObject.h"
#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace tasks {

class RevokePaidAccessTask : public Task {
	ManagedWeakReference<BuildingObject*> building;
public:
	RevokePaidAccessTask(BuildingObject* build);

	void run();
};

} // namespace tasks
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::tasks;
