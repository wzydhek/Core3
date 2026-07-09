#include "DroidPlaybackEvent.h"

DroidPlaybackEvent::DroidPlaybackEvent(DroidPlaybackModuleDataComponent* module, CreatureObject* player, int perfIndex, int action) : Task() {
	this->module = module;
	this->action = action;
	this->performanceIndex = perfIndex;
	this->player = player;
}

void DroidPlaybackEvent::run() {
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
			droid->removePendingTask("droid_playback_event");
			return;
		}
	}

	// Check droid states
	if (droid->isDead() || droid->isIncapacitated()) {
		module->deactivate();
		droid->removePendingTask("droid_playback_event");
		return;
	}

	// Droid must have power
	if (!droid->hasPower()) {
		module->deactivate();
		droid->showFlyText("npc_reaction/flytext", "low_power", 204, 0, 0); // "*Low Power*"
		droid->removePendingTask("droid_playback_event");
		return;
	}

	Locker plock(player);
	Locker crossLock(droid, player);

	if (action == SET_TRACK)
		module->setTrack(player, performanceIndex);
	if (action == CHANGE_SONG)
		module->songChanged(player);
	if (action == STOP_PLAYING)
		module->songStopped(player);
}