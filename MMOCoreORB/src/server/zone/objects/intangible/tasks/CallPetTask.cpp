#include "CallPetTask.h"

CallPetTask::CallPetTask(PetControlDevice* controlDevice, CreatureObject* creo, const String& task) {
	player = creo;
	device = controlDevice;
	taskName = task;
}

void CallPetTask::run() {
	Locker locker(player);

	player->removePendingTask("call_pet");

	if (player->isInCombat())
		return;

	Locker locker2(device);
	Locker clocker(device->getControlledObject(), player);
	device->spawnObject(player);
}