/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file SampleResultsTask.h
 * \author Kyle Burkhardt
 * \date 5-03-10
 */

#pragma once

#include "server/zone/objects/transaction/TransactionLog.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "ResourceSpawner.h"

class ResourceSpawner;

class SampleResultsTask : public Task {

protected:
	ManagedReference<CreatureObject*> playerCreature;
	Reference<const ResourceSpawner*> resourceSpawner;
	float density;
	String resname;

public:
	SampleResultsTask(ManagedReference<CreatureObject*> play, const ResourceSpawner* spawner, float d, String rname);

	void run();

};
