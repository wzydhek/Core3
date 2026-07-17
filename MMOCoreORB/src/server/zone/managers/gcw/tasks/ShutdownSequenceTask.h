/*
 * ShutdownSequenceTask.h
 *
 *  Created on: Feb 20, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class ShutdownSequenceTask : public Task {

	ManagedReference<BuildingObject*> buildingObject;
	ManagedReference<GCWManager*> gcwManager;
	ManagedReference<CreatureObject*> creature;
	ManagedReference<SceneObject*> hqTerminal;
	bool bDestruction;

public:

	ShutdownSequenceTask(GCWManager* gcwMan, BuildingObject* building, CreatureObject* player, SceneObject* term, bool isDestruction);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
