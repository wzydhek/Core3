/*
 * InsertAstromechIntoShipTask.h
 */

#pragma once

#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/objects/intangible/tasks/PetControlDeviceStoreTask.h"
#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/SpaceZone.h"

class InsertAstromechIntoShipTask : public Task, public Logger {
	ManagedWeakReference<ShipObject*> shipObj;

public:
	InsertAstromechIntoShipTask(ShipObject* shipObj);

	void run();
};
