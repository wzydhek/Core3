#include "RemoveDisabledInvulnerableTask.h"
#include "server/zone/Zone.h"

RemoveDisabledInvulnerableTask::RemoveDisabledInvulnerableTask(ShipAiAgent* shipO) {
	ship = shipO;

	auto zone = shipO->getZone();

	if (zone != nullptr) {
		setCustomTaskQueue(zone->getZoneName());
	}
}

void RemoveDisabledInvulnerableTask::run() {
	ManagedReference<ShipAiAgent*> strongShip = ship.get();

	if (strongShip == nullptr) {
		return;
	}

	Locker locker(strongShip);

	auto zone = strongShip->getZone();

	if (zone == nullptr) {
		return;
	}

	strongShip->removeShipFlag(ShipFlag::DISABLED_INVULNERABLE);
}