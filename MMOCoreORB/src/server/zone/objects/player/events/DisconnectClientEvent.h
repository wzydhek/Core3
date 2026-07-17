/*
 * DisconnectClientEvent.h
 *
 *  Created on: Oct 14, 2010
 *      Author: oru
 */

#pragma once

#include "server/zone/objects/player/PlayerObject.h"

#ifdef WITH_SWGREALMS_API
	#include "server/login/SWGRealmsAPI.h"
#endif // WITH_SWGREALMS_API

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class DisconnectClientEvent : public Task {
	ManagedReference<CreatureObject*> player;
	ManagedReference<ZoneClientSession*> client;
	int eventType;

public:
	const static int DISCONNECT = 1;
	const static int LOGOUT = 2;
	const static int SETLINKDEAD = 3;

public:
	DisconnectClientEvent(CreatureObject* pl, ZoneClientSession* cl, int type);

	void run();

};

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;
