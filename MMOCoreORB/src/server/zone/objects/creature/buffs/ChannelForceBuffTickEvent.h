/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/buffs/ChannelForceBuff.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class ChannelForceBuffTickEvent : public Task {
	ManagedWeakReference<ChannelForceBuff*> buffObject;

public:
	ChannelForceBuffTickEvent(ChannelForceBuff* buff);

	void run();

};

}
}
}
}
}

using namespace server::zone::objects::creature::buffs;
