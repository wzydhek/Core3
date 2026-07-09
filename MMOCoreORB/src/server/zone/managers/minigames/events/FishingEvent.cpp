#include "FishingEvent.h"

FishingEvent::FishingEvent(CreatureObject* player, int state) : Task(7000) {
	weakPlayer = player;
	fishingState = state;
}

void FishingEvent::run() {
	ManagedReference<CreatureObject*> player = weakPlayer.get();

	if (player == nullptr) {
		return;
	}

	auto zoneProcessServer = player->getZoneProcessServer();

	if (zoneProcessServer == nullptr) {
		clearPlayerFishing(player);
		return;
	}

	auto fishingManager = zoneProcessServer->getFishingManager();

	if (fishingManager == nullptr) {
		clearPlayerFishing(player);
		return;
	}

	try {
		Locker lock(player);

		ManagedReference<FishingManager*> manager = zoneProcessServer->getFishingManager();

		if (fishingState != FishingManagerImplementation::NOTFISHING) {
			manager->continueFishing(player);
		} else {
			manager->stopFishingEvent(player);
		}
	} catch (...) {
		throw;
	}
}

void FishingEvent::clearPlayerFishing(CreatureObject* player) {
	if (player == nullptr) {
		return;
	}

	Locker lock(player);

	player->setMoodString("none");
}