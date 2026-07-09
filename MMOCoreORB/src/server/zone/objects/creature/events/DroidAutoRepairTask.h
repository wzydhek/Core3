/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/tangible/components/droid/DroidAutoRepairModuleDataComponent.h"
#include "server/zone/objects/group/GroupObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidAutoRepairTask : public Task {

	Reference<DroidAutoRepairModuleDataComponent*> module;

public:
	DroidAutoRepairTask(DroidAutoRepairModuleDataComponent* module);

	void run();

private:
	void healDroid(DroidObject* healer, DroidObject* droid, int amount);

};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
