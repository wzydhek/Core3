#include "PobCellDotTask.h"

PobCellDotTask::PobCellDotTask(PobShipObject* ship) : Task() {
	weakShip = ship;
}

void PobCellDotTask::run() {
	auto pobShip = weakShip.get();

	if (pobShip == nullptr) {
		return;
	}

	Locker lock(pobShip);

	if (!pobShip->isShipLaunched()) {
		return;
	}

	if (pobShip->triggerCellDamageOverTime()) {
		pobShip->applyPobComponentDot();

		// pobShip->info(true) << "PobCellDotTask -- Re-Scheduling for " << PobShipObject::CELL_DOT_TICK * 1000;

		schedule(PobShipObject::CELL_DOT_TICK * 1000);
	}
}

void PobCellDotTask::schedule(uint64 delay) {
	auto pobShip = weakShip.get();

	if (pobShip != nullptr) {
		auto zone = pobShip->getZone();

		if (zone != nullptr) {
			setCustomTaskQueue(zone->getZoneName());
		}
	}

	try {
		Task::schedule(delay);
	} catch (...) {
	}
}