
#pragma once

#include "server/zone/objects/scene/SceneObject.h"

class DespawnDynamicSpawnTask : public Task {
	ManagedReference<SceneObject*> spawn;

public:
	DespawnDynamicSpawnTask(SceneObject* sceno);

	void run();
};
