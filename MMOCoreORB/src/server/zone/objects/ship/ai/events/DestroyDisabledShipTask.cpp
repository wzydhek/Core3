#include "DestroyDisabledShipTask.h"

DestroyDisabledShipTask::DestroyDisabledShipTask(ShipAiAgent* agent) : Task(1000) {
	shipAgent = agent;
}

void DestroyDisabledShipTask::run() {
	ManagedReference<ShipAiAgent*> strongAgent = shipAgent.get();

	if (strongAgent == nullptr) {
		return;
	}

	Locker locker(strongAgent);

	strongAgent->removePendingTask("destroy_disabled");

	if (strongAgent->isShipDestroyed()) {
		// strongAgent->info(true) << "DestroyDisabledShipTask -- ship already destroyed, skipping";
		return;
	}

	if (!strongAgent->isShipDisabled()) {
		// strongAgent->info(true) << "DestroyDisabledShipTask -- ship no longer disabled, skipping";
		return;
	}

	// strongAgent->info(true) << "DestroyDisabledShipTask -- destroying disabled ship: " << strongAgent->getDisplayedName();

	auto destroyTask = new DestroyShipTask(strongAgent);

	if (destroyTask == nullptr) {
		strongAgent->destroyObjectFromWorld(true);
	} else {
		destroyTask->execute();
	}

	Core::getTaskManager()->scheduleTask(
		[strongAgent]() {
			if (strongAgent == nullptr) {
				return;
			}

			Locker lock(strongAgent);

			strongAgent->notifyObjectDestructionObservers(nullptr, 0, true);
		},
		"notifyShipDestroyLambda", 200);
}

void DestroyDisabledShipTask::schedule(uint64 delay) {
	ManagedReference<ShipAiAgent*> strongAgent = shipAgent.get();

	if (strongAgent != nullptr) {
		auto zone = strongAgent->getZone();

		if (zone != nullptr) {
			setCustomTaskQueue(zone->getZoneName());
		}
	}

	try {
		Task::schedule(delay);
	} catch (...) {
	}
}