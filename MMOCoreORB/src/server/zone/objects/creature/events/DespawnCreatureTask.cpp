#include "DespawnCreatureTask.h"

DespawnCreatureTask::DespawnCreatureTask(AiAgent* creature) {
	agent = creature;

	auto zone = creature->getZone();

	if (zone != nullptr) {
		setCustomTaskQueue(zone->getZoneName());
	}
}

void DespawnCreatureTask::run() {
	Locker locker(agent);

	Zone* zone = agent->getZone();

	agent->removePendingTask("despawn");

	if (zone == nullptr) {
		agent->destroyAllWeapons();

		return;
	}

	agent->destroyObjectFromWorld(false);
	agent->notifyDespawn(zone);
}