#include "DespawnDynamicSpawnTask.h"

DespawnDynamicSpawnTask::DespawnDynamicSpawnTask(SceneObject* sceno) {
	spawn = sceno;
}

void DespawnDynamicSpawnTask::run() {
	Locker locker(spawn);

	Zone* zone = spawn->getZone();

	if (zone == nullptr)
		return;

	spawn->destroyObjectFromWorld(true);
}