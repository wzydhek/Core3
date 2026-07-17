/*
 * ClearClientEvent.h
 *
 *  Created on: Feb 14, 2010
 *      Author: oru
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class ClearClientEvent : public Task {
	ManagedReference<CreatureObject*> player;
	ManagedReference<ZoneClientSession*> client;

public:
	ClearClientEvent(CreatureObject* pl, ZoneClientSession* cl);

	void run();

};

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;
