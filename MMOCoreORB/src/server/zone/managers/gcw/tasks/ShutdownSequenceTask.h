/*
 * ShutdownSequenceTask.h
 *
 *  Created on: Feb 20, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

class ShutdownSequenceTask : public Task {

	ManagedReference<BuildingObject*> buildingObject;
	ManagedReference<GCWManager*> gcwManager;
	ManagedReference<CreatureObject*> creature;
	ManagedReference<SceneObject*> hqTerminal;
	bool bDestruction;

public:

	ShutdownSequenceTask(GCWManager* gcwMan, BuildingObject* building, CreatureObject* player, SceneObject* term, bool isDestruction);

	void run();
};
