/*
 * BaseDestructionTask.h
 *
 *  Created on: Nov 2, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

class BaseDestructionTask : public Task {
	ManagedWeakReference<GCWManager*> gcwManager;
	ManagedWeakReference<BuildingObject*> buildingObject;
	int countDown;
public:
	BaseDestructionTask(GCWManager* manager, BuildingObject* building);

	void run();

	int getCountdown();
};
