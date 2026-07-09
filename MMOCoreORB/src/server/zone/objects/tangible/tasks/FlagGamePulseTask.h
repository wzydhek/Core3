
#pragma once

#include "server/zone/objects/tangible/eventperk/FlagGame.h"
#include "templates/faction/Factions.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tasks {

class FlagGamePulseTask : public Task {
	ManagedReference<FlagGame*> game;

public:
	FlagGamePulseTask(FlagGame* ga);

	void run();
};

}
}
}
}
}

using namespace server::zone::objects::tangible::tasks;
