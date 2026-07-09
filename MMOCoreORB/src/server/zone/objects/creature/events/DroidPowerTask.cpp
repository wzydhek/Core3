#include "DroidPowerTask.h"

DroidPowerTask::DroidPowerTask(DroidObject* droid) : Task() {
	this->droid = droid;
}

void DroidPowerTask::run() {
	ManagedReference<DroidObject*> strongDroid = droid.get();

	if (strongDroid == nullptr)
		return;

	Locker locker(strongDroid);

	strongDroid->removePendingTask("droid_power");

	// Check if droid is spawned
	if (strongDroid->getLocalZone() == nullptr) { // Not outdoors

		ManagedReference<SceneObject*> parent = strongDroid->getParent().get();
		if (parent == nullptr || !parent.get()->isCellObject()) { // Not indoors either
			return;
		}
	}

	// Consume power if available
	if (strongDroid->hasPower()) {
		strongDroid->usePower(4);
		strongDroid->runModulePowerDrain();
	}

	strongDroid->addPendingTask("droid_power", this, 120000); // 2 min
}