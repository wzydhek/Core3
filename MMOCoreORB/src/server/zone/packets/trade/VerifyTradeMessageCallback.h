/*
 * VerifyTradeMessageCallback.h
 *
 *  Created on: 07/06/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

class VerifyTradeMessageCallback : public MessageCallback {


public:
	VerifyTradeMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) :
		MessageCallback(client, server) {

	}

	void parse(Message* message) {

	}

	void run() {
		ManagedReference<CreatureObject*> player = client->getPlayer();

		if (player == nullptr)
			return;

		auto zoneServer = server->getZoneServer();

		if (zoneServer == nullptr)
			return;

		auto playerMan = zoneServer->getPlayerManager();

		if (playerMan == nullptr)
			return;

		Locker lock(player);

		playerMan->handleVerifyTradeMessage(player);
	}

};
