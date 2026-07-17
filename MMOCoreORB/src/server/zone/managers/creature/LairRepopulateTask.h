#pragma once

#include "server/zone/managers/creature/LairObserver.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class LairRepopulateTask : public Task {
	WeakReference<TangibleObject*> lair;
	WeakReference<LairObserver*> observer;

public:
	LairRepopulateTask(TangibleObject* obj, LairObserver* observer);

	void run();
};

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;
