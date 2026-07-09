#include "DespawnAiShipOnNoPlayersInRange.h"
#include "server/zone/Zone.h"

DespawnAiShipOnNoPlayersInRange::DespawnAiShipOnNoPlayersInRange(ShipAiAgent* shipO) {
	ship = shipO;

	auto zone = shipO->getZone();

	if (zone != nullptr) {
		setCustomTaskQueue(zone->getZoneName());
	}
}

void DespawnAiShipOnNoPlayersInRange::run() {
	ManagedReference<ShipAiAgent*> strongShip = ship.get();

	if (strongShip == nullptr) {
		return;
	}

	Locker locker(strongShip);

	strongShip->clearDespawnEvent();

	auto zone = strongShip->getZone();

	if (zone == nullptr) {
		return;
	}

	if (!strongShip->getDespawnOnNoPlayerInRange()) {
		return;
	}

	if (strongShip->getNumberOfPlayersInRange() <= 0) {
		strongShip->destroyObjectFromWorld(true);

		// strongShip->info(true) << strongShip->getDisplayedName() << " removed from ShipAgent from world";
	}
}