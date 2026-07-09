#include "DespawnShipAgentTask.h"

DespawnShipAgentTask::DespawnShipAgentTask(ShipAiAgent* agent) : Task(1000) {
	shipAgent = agent;
}

void DespawnShipAgentTask::run() {
	Locker locker(shipAgent);

	shipAgent->removePendingTask("despawn");

	shipAgent->destroyObjectFromWorld(false);
}

void DespawnShipAgentTask::schedule(uint64 delay) {
	if (shipAgent != nullptr) {
		auto zone = shipAgent->getZone();

		if (zone != nullptr) {
			setCustomTaskQueue(zone->getZoneName());
		}
	}

	try {
		Task::schedule(delay);
	} catch (...) {
	}
}