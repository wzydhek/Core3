
#pragma once

#include "server/zone/objects/tangible/Instrument.h"
#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tasks {

class InstrumentPulseTask : public Task {
	WeakReference<Instrument*> instrument;

public:
	InstrumentPulseTask(Instrument* inst);

	void run();
};

}
}
}
}
}

using namespace server::zone::objects::tangible::tasks;
