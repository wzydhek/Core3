
#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/tangible/deed/eventperk/EventPerkDeed.h"
#include "server/zone/objects/tangible/components/EventPerkDataComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tasks {

class RemoveEventPerkDeedTask : public Task {
	ManagedWeakReference<EventPerkDeed*> weakDeed;

public:
	RemoveEventPerkDeedTask(EventPerkDeed* deed);

	void run();
};

} // namespace tasks
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::tasks;
