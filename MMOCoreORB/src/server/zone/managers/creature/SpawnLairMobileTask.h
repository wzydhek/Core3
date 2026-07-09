/*
 * SpawnLairMobileTask.h
 *
 * Created on: 2024-07-06
 * Author: Hakry
 */

#pragma once

#include "server/zone/objects/tangible/LairObject.h"
#include "server/zone/managers/creature/LairObserver.h"

class SpawnLairMobileTask : public Task {
	ManagedWeakReference<LairObject*> lairWeak;
	int spawnNumber;
	String mobileString;
	bool spawnPassive;

public:
	SpawnLairMobileTask(LairObject* lair, int spawnNum, String mobileStr, bool passive);

	void run();
};
