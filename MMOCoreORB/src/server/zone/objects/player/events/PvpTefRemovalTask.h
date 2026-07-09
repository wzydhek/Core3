
#pragma once

#include "server/zone/objects/player/PlayerObject.h"
#include "templates/params/creature/ObjectFlag.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class PvpTefRemovalTask: public Task {
	ManagedWeakReference<CreatureObject*> creature;

public:
	PvpTefRemovalTask(CreatureObject* creo);

	void run();
};

}
}
}
}
}

using namespace server::zone::objects::player::events;
