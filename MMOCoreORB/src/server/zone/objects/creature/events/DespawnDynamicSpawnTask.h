
#pragma once

#include "server/zone/objects/scene/SceneObject.h"

class DespawnDynamicSpawnTask : public Task {
	ManagedReference<SceneObject*> spawn;

public:
	DespawnDynamicSpawnTask(SceneObject* sceno) {
		spawn = sceno;
	}

	void run() {
		Locker locker(spawn);

		Zone* zone = spawn->getZone();

		if (zone == nullptr)
			return;

		spawn->destroyObjectFromWorld(true);

	}
};
