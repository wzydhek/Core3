#include "PetControlDeviceStoreTask.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/creature/CreatureObject.h"

PetControlDeviceStoreTask::PetControlDeviceStoreTask(PetControlDevice* device, CreatureObject* playerCreo, bool force) {
	this->device = device;
	this->force = force;
	this->playerCreo = playerCreo;
}

void PetControlDeviceStoreTask::run() {
	auto petDevice = device.get();
	auto player = playerCreo.get();

	if (petDevice == nullptr || player == nullptr)
		return;

	ManagedReference<TangibleObject*> controlledObject = petDevice->getControlledObject();

	if (controlledObject == nullptr || !controlledObject->isAiAgent())
		return;

	Locker lock(petDevice);

	petDevice->storeObject(player, force);
}