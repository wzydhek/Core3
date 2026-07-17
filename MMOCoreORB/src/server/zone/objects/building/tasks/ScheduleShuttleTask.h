
#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/planet/PlanetManager.h"

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace tasks {

class ScheduleShuttleTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> shuttleObject;
	Zone* zone;

public:
	ScheduleShuttleTask(CreatureObject* shuttle, Zone* zon);

	void run();
};

} // namespace tasks
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::tasks;
