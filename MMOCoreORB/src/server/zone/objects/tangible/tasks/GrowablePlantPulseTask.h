#pragma once

#include "server/zone/objects/tangible/misc/PlantObject.h"
#include "server/zone/ZoneServer.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tasks {

class GrowablePlantPulseTask : public Task {
	WeakReference<PlantObject*> plant;

public:
	GrowablePlantPulseTask(PlantObject* pl);

	void run();
};

}
}
}
}
}

using namespace server::zone::objects::tangible::tasks;
