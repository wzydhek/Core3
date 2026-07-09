/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/tangible/components/droid/DroidMerchantModuleDataComponent.h"
#include "server/chat/ChatManager.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidMerchantBarkerTask : public Task, public Logger {

	Reference<DroidMerchantModuleDataComponent*> module;

public:
	DroidMerchantBarkerTask(DroidMerchantModuleDataComponent* module);

	void run();

};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
