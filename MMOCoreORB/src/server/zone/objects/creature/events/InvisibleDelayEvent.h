/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

/**
 * file InvisibleDelayEvent.h
 * author Polonel
 * date 10.01.2010
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "templates/creature/PlayerCreatureTemplate.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class InvisibleDelayEvent: public Task {
	ManagedReference<CreatureObject*> player;

public:
	InvisibleDelayEvent(CreatureObject* pl);

	void run();

};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
