
#pragma once

#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class RemoveSpouseTask : public Task {
	ManagedReference<CreatureObject*> creature;

public:
	RemoveSpouseTask(CreatureObject* creatureObject);

	void run();
};

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;
