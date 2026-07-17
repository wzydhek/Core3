/*
 * StructureConstructionCompleteTask.h
 *
 *  Created on: Jun 13, 2011
 *      Author: crush
 */


#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sessions/PlaceStructureSession.h"

namespace server {
namespace zone {
namespace managers {
namespace structure {
namespace tasks {

class StructureConstructionCompleteTask : public Task {
	ManagedWeakReference<CreatureObject*> creatureObject;

public:
	StructureConstructionCompleteTask(CreatureObject* creature);

	void run();
};

} // namespace tasks
} // namespace structure
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::structure::tasks;
