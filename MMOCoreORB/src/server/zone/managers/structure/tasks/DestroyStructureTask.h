/*
 * DestroyStructureTask.h
 *
 *  Created on: Jun 29, 2013
 *      Author: TheAnswer
 */

#pragma once

#include "server/zone/Zone.h"
#include "server/zone/objects/structure/StructureObject.h"
#include "server/zone/objects/cell/CellObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/packets/object/PlayClientEffectObjectMessage.h"
#include "server/zone/packets/scene/PlayClientEffectLocMessage.h"

namespace server {
namespace zone {
namespace managers {
namespace structure {
namespace tasks {

class DestroyStructureTask : public Task {
protected:
	ManagedReference<StructureObject*> structureObject;
	bool playEffect;
	bool killOccupants;

public:
	DestroyStructureTask(StructureObject* structure, bool doEffect = false, bool killStuff = false);

	void run();
};

} // namespace tasks
} // namespace structure
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::structure::tasks;
