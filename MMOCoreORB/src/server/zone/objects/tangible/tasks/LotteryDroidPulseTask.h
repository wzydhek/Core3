
#pragma once

#include "server/zone/objects/tangible/eventperk/LotteryDroid.h"
#include "server/zone/objects/tangible/deed/eventperk/EventPerkDeed.h"
#include "server/zone/objects/tangible/components/EventPerkDataComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tasks {

class LotteryDroidPulseTask : public Task {
	WeakReference<LotteryDroid*> droid;

public:
	LotteryDroidPulseTask(LotteryDroid* dr);

	void run();
};

}
}
}
}
}

using namespace server::zone::objects::tangible::tasks;
