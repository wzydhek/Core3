#include "ShipRecoveryEvent.h"

ShipRecoveryEvent::ShipRecoveryEvent(ShipObject* shipObj) : Task(1000) {
	weakShip = shipObj;
}

void ShipRecoveryEvent::run() {
	ManagedReference<ShipObject*> ship = weakShip.get();

	if (ship == nullptr) {
		return;
	}

	Locker lock(ship);

	ship->doRecovery(1000);
}

void ShipRecoveryEvent::schedule(uint64 delay) {
	ManagedReference<ShipObject*> ship = weakShip.get();

	if (ship != nullptr) {
		auto zone = ship->getZone();

		if (zone != nullptr) {
			setCustomTaskQueue(zone->getZoneName());
		}
	}

	try {
		Task::schedule(delay);
	} catch (...) {
	}
}