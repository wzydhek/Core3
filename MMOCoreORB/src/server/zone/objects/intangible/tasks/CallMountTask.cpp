#include "CallMountTask.h"

CallMountTask::CallMountTask(VehicleControlDevice* controlDevice, CreatureObject* creo, const String& task) {
	player = creo;
	device = controlDevice;
	taskName = task;
}

void CallMountTask::run() {
	Locker locker(player);

	player->removePendingTask("call_mount");

	if (player->isInCombat())
		return;

	ManagedReference<TangibleObject*> vehicle = device->getControlledObject();

	if (vehicle == nullptr)
		return;

	Locker locker2(device);
	Locker clocker(vehicle, player);
	device->spawnObject(player);
}