/*
 * RemoveNoSpawnAreaTask.h
 *
 *  Created on: 16/05/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/area/ActiveArea.h"

class RemoveNoSpawnAreaTask : public Task {
	ManagedWeakReference<ActiveArea*> area;

public:
	RemoveNoSpawnAreaTask(ActiveArea* camp);

	void run();
};
