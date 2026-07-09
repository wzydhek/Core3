
#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/intangible/ControlDevice.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/objects/intangible/tasks/PetControlDeviceStoreTask.h"
#include "server/zone/objects/intangible/ShipControlDevice.h"
#include "server/zone/objects/intangible/tasks/StoreShipTask.h"

class StoreSpawnedChildrenTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> play;
	Vector<ManagedReference<ControlDevice*>> devices;

public:
	StoreSpawnedChildrenTask(CreatureObject* creo, Vector<ManagedReference<ControlDevice*>>&& dev);

	void run();
};
