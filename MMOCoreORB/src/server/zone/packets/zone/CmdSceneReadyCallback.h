/*
 * CmdSceneReadyCallback.h
 *
 *  Created on: Sep 6, 2009
 *      Author: theanswer
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "CmdSceneReady.h"

class CmdSceneReadyCallback : public MessageCallback {
public:
	CmdSceneReadyCallback(ZoneClientSession* client, ZoneProcessServer* server):MessageCallback(client, server) {
	}

	void parse(Message* message) {
	}

	void run() {
		ManagedReference<CreatureObject*> player = client->getPlayer();

		if (player == nullptr) {
			return;
		}

		Locker _locker(player);

		auto ghost = player->getPlayerObject();

		if (ghost != nullptr) {
			ghost->notifySceneReady();
		}
	}
};
