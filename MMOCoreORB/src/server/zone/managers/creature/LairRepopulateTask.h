#pragma once

#include "server/zone/managers/creature/LairObserver.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class LairRepopulateTask : public Task {
	WeakReference<TangibleObject*> lair;
	WeakReference<LairObserver*> observer;

public:
	LairRepopulateTask(TangibleObject* obj, LairObserver* observer);

	void run();
};
