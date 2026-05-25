/*
 * ObjectMenuSelect.h
 *
 *  Created on: 12/08/2009
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ObjectMenuSelectCallback : public MessageCallback {
	uint64 objectID;
	uint8 radialID;
public:
	ObjectMenuSelectCallback(ZoneClientSession* client, ZoneProcessServer* server) :
		MessageCallback(client, server), objectID(0), radialID(0) {

	}

	void parse(Message* message) {
		objectID = message->parseLong();
		radialID = message->parseByte();
	}

	void run() {
		ManagedReference<CreatureObject*> player = client->getPlayer();

		if (player != nullptr) {
			RadialManager* radialManager = server->getZoneServer()->getRadialManager();
			radialManager->handleObjectMenuSelect(player, radialID, objectID);
		}
	}
};
