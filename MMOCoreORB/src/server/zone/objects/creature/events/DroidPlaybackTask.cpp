#include "DroidPlaybackTask.h"

DroidPlaybackTask::DroidPlaybackTask(DroidPlaybackModuleDataComponent* module) : Task() {
	this->module = module;
	playing = false;
}

void DroidPlaybackTask::run() {
	if (module == nullptr)
		return;

	DroidObject* droid = module->getDroidObject();

	if (droid == nullptr)
		return;

	Locker locker(droid);

	if (droid->getLocalZone() == nullptr) { // Not outdoors
		ManagedReference<SceneObject*> parent = droid->getParent().get();
		if (parent == nullptr || !parent->isCellObject()) { // Not indoors either
			module->deactivate();
			droid->removePendingTask("droid_playback");
			return;
		}
	}

	// Check droid states
	if (droid->isDead() || droid->isIncapacitated()) {
		module->deactivate();
		droid->removePendingTask("droid_playback");
		return;
	}

	// Droid must have power
	if (!droid->hasPower()) {
		module->deactivate();
		droid->showFlyText("npc_reaction/flytext", "low_power", 204, 0, 0); // "*Low Power*"
		droid->removePendingTask("droid_playback");
		return;
	}

	int performanceIndex = module->getPerformanceIndex();

	if (performanceIndex == 0) {
		module->deactivate();
		return;
	}

	// recheck every 10 seconds for power on the droid
	droid->addPendingTask("droid_playback", this, 10000);
}