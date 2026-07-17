/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class BurstRunNotifyAvailableEvent : public Task {
	ManagedWeakReference<CreatureObject*> creo;

public:
	BurstRunNotifyAvailableEvent(CreatureObject* cr);

	void run();

};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
