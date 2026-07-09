/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/tangible/components/droid/DroidStimpackModuleDataComponent.h"
#include "server/zone/objects/group/GroupObject.h"
#include "server/zone/objects/tangible/pharmaceutical/StimPack.h"
#include "templates/params/creature/CreatureAttribute.h"
#include "server/zone/objects/tangible/component/droid/DroidComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidStimpackTask : public Task {

	ManagedReference<DroidObject*> droid;
	ManagedReference<CreatureObject*> target;
	String droidName;

public:
	DroidStimpackTask(DroidObject* droid, CreatureObject* player, String droidName);

	void run();
};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
