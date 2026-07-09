#include "DroidSkillModTask.h"

DroidSkillModTask::DroidSkillModTask(DroidObject* droid, CreatureObject* owner) : Task() {
	this->droid = droid;
	this->owner = owner;
}

void DroidSkillModTask::run() {
	ManagedReference<DroidObject*> strongDroidRef = droid;
	ManagedReference<CreatureObject*> strongOwnerRef = owner;

	if (strongDroidRef == nullptr || strongOwnerRef == nullptr)
		return;

	Locker locker(strongDroidRef);

	strongDroidRef->removePendingTask("droid_skill_mod");

	// Check if droid is spawned
	if (strongDroidRef->getLocalZone() == nullptr) { // Not outdoors
		ManagedReference<SceneObject*> parent = strongDroidRef->getParent().get();
		if (parent == nullptr || !parent->isCellObject()) { // Not indoors either
			return;
		}
	}

	Locker crossLocker(strongOwnerRef, strongDroidRef);

	// refresh the skill mods if qualifying.
	strongDroidRef->unloadSkillMods(strongOwnerRef);

	// various sources list 15m as the cut-off for all droid skill mods.
	// verify that it is in range, has power, not dead, and not incapped
	if (strongOwnerRef->isInRange(strongDroidRef, 15) && !strongDroidRef->isDead() && !strongDroidRef->isIncapacitated() && strongDroidRef->hasPower())
		strongDroidRef->loadSkillMods(strongOwnerRef);

	strongDroidRef->addPendingTask("droid_skill_mod", this, 3000); // 3 sec
}