#pragma once

#include "engine/engine.h"
#include "server/zone/objects/intangible/PetControlDevice.h"

class PetControlDeviceStoreTask : public Task {
	ManagedWeakReference<PetControlDevice*> device;
	ManagedWeakReference<CreatureObject*> playerCreo;
	bool force;

public:
	PetControlDeviceStoreTask(PetControlDevice* device, CreatureObject* playerCreo, bool force);

	void run();
};
