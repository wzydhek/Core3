#include "PlayerRecoveryEvent.h"

PlayerRecoveryEvent::PlayerRecoveryEvent(PlayerObject* ghost) : Task(2000) {
	weakGhost = ghost;
	startTime.updateToCurrentTime();
}

PlayerRecoveryEvent::~PlayerRecoveryEvent() {
}

void PlayerRecoveryEvent::run() {
	ManagedReference<PlayerObject*> ghost = weakGhost.get();

	if (ghost == nullptr) {
		return;
	}

	ManagedReference<SceneObject*> strongParent = ghost->getParent().get();

	if (strongParent == nullptr) {
		return;
	}

	Locker lock(strongParent);

	if (!ghost->isOnline() && !ghost->isLinkDead()) {
		return;
	}

	ghost->doRecovery(startTime.miliDifference());
}

void PlayerRecoveryEvent::schedule(uint64 delay) {
	startTime.updateToCurrentTime();
	Task::schedule(delay);
}