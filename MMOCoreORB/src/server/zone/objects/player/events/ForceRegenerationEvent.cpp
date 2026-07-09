#include "ForceRegenerationEvent.h"

ForceRegenerationEvent::ForceRegenerationEvent(PlayerObject* ghost) {
	weakGhost = ghost;
}

void ForceRegenerationEvent::run() {
	ManagedReference<PlayerObject*> ghost = weakGhost.get();

	if (ghost == nullptr) {
		return;
	}

	ManagedReference<CreatureObject*> player = dynamic_cast<CreatureObject*>(ghost->getParent().get().get());

	if (player == nullptr) {
		return;
	}

	Locker lock(player);

	if (!ghost->isOnline() && !ghost->isLinkDead()) {
		return;
	}

	int forceMax = ghost->getForcePowerMax();
	int forceCurrent = ghost->getForcePower();

	if (forceMax < 1 || ((forceMax - forceCurrent) < 1)) {
		return;
	}

	ghost->doForceRegen();
}