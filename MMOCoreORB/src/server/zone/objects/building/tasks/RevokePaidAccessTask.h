/*
 * RevokePaidAccessTask.h
 *
 *  Created on: June 2, 2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/building/BuildingObject.h"
#include "engine/engine.h"

class RevokePaidAccessTask : public Task {
	ManagedWeakReference<BuildingObject*> building;
public:
	RevokePaidAccessTask(BuildingObject* build) : Task() {
		building = build;
	}

	void run() {

		ManagedReference<BuildingObject*> strongRef = building;

		if (strongRef == nullptr) {
			return;
		}

		Locker _lock(strongRef);
		strongRef->updatePaidAccessList();
	}
};
