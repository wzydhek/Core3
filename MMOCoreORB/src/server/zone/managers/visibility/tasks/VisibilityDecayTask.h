/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/managers/visibility/VisibilityManager.h"

namespace server {
namespace zone {
namespace managers {
namespace visibility {
namespace tasks {

class VisibilityDecayTask : public Task {
public:
	VisibilityDecayTask() : Task() {
	}

	void run() {
		VisibilityManager::instance()->performVisiblityDecay();
		reschedule(VisibilityManager::instance()->getVisDecayTickRate() * 1000);
	}
};

}
}
}
}
}

using namespace server::zone::managers::visibility::tasks;
