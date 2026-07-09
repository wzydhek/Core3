#include "StoreSpawnedChildrenTask.h"

StoreSpawnedChildrenTask::StoreSpawnedChildrenTask(CreatureObject* creo, Vector<ManagedReference<ControlDevice*>>&& dev) : play(creo), devices(std::move(dev)) {
}

void StoreSpawnedChildrenTask::run() {
	ManagedReference<CreatureObject*> player = play.get();

	if (player == nullptr) {
		return;
	}

	Locker locker(player);

	// info(true) << "StoreSpawnedChildrenTask -- for " << player->getDisplayedName() << " Total Devices: " << devices.size();

	for (int i = 0; i < devices.size(); ++i) {
		ManagedReference<ControlDevice*> controlDevice = devices.get(i).get();

		if (controlDevice == nullptr)
			continue;

		if (controlDevice->isPetControlDevice()) {
			CreatureObject* pet = cast<CreatureObject*>(controlDevice->getControlledObject());

			if (pet == nullptr)
				continue;

			if (pet->isDroidObject()) {
				auto droidRoot = pet->getRootParent();

				if (droidRoot != nullptr && droidRoot->isShipObject() && droidRoot->getSlottedObject("ship_droid") == pet) {
					continue;
				}
			}

			Locker clocker(pet, player);

			PetControlDeviceStoreTask* storeTask = new PetControlDeviceStoreTask(controlDevice.castTo<PetControlDevice*>(), player, true);

			if (storeTask != nullptr)
				storeTask->execute();
		} else if (controlDevice->isShipControlDevice()) {
			auto ghost = player->getPlayerObject();

			if (ghost == nullptr)
				continue;

			auto shipDevice = controlDevice.castTo<ShipControlDevice*>();

			if (shipDevice == nullptr || !shipDevice->isShipLaunched())
				continue;

			StoreShipTask* storeTask = new StoreShipTask(player, shipDevice, ghost->getSpaceLaunchZone(), ghost->getSpaceLaunchLocation());

			// info(true) << "StoreSpawnedChildrenTask -- executing StoreShipTask - for Ship Device: " << shipDevice->getDisplayedName();

			if (storeTask != nullptr) {
				storeTask->execute();
			}
		} else {
			Locker deviceLocker(controlDevice, player);

			controlDevice->storeObject(player, true);
		}
	}
}