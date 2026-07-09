/*
 * SelectCharacterCallback.h
 *
 *  Created on: Sep 5, 2009
 *      Author: theanswer
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/ZoneServer.h"

// #define DEBUG_SELECT_CHAR_CALLBACK

class SelectCharacterCallback : public MessageCallback {
	uint64 characterID;
public:
	SelectCharacterCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	static void connectPlayer(SceneObject* obj, uint64_t characterID, CreatureObject* player, ZoneClientSession* client, ZoneServer* zoneServer);

	#ifdef WITH_SWGREALMS_API

	static void connectApprovedPlayer(SceneObject* obj, uint64_t characterID, CreatureObject* player, ZoneClientSession* client, ZoneServer* zoneServer);

	#endif // WITH_SWGREALMS_API

	void run();
};
