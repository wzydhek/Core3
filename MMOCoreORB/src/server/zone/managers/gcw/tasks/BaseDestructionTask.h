/*
 * BaseDestructionTask.h
 *
 *  Created on: Nov 2, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class BaseDestructionTask : public Task {
	ManagedWeakReference<GCWManager*> gcwManager;
	ManagedWeakReference<BuildingObject*> buildingObject;
	int countDown;
public:
	BaseDestructionTask(GCWManager* manager, BuildingObject* building);

	void run();

	int getCountdown();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
