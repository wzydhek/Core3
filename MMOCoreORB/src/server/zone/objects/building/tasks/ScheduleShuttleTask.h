
#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/planet/PlanetManager.h"

class ScheduleShuttleTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> shuttleObject;
	Zone* zone;

public:
	ScheduleShuttleTask(CreatureObject* shuttle, Zone* zon);

	void run();
};
