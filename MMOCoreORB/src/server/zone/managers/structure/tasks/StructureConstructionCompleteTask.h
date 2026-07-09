/*
 * StructureConstructionCompleteTask.h
 *
 *  Created on: Jun 13, 2011
 *      Author: crush
 */


#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sessions/PlaceStructureSession.h"

class StructureConstructionCompleteTask : public Task {
	ManagedWeakReference<CreatureObject*> creatureObject;

public:
	StructureConstructionCompleteTask(CreatureObject* creature);

	void run();
};
