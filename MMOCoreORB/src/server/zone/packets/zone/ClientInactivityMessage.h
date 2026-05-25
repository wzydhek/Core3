/*
 * ClientInactivityMessage.h
 *
 *  Created on: 15/08/2009
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ClientInactivityMessageCallback : public MessageCallback {
	byte flag;

public:
	ClientInactivityMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) :
		MessageCallback(client, server), flag(0) {

	}

	void parse(Message* message) {
		flag = message->parseByte();
	}

	void run() {
		ManagedReference<CreatureObject*> player = client->getPlayer();

		if (player != nullptr) {
			StringBuffer msg;
			msg << "ClientInactivityMessage with flag " << hex << flag << " received";
			player->info(msg.toString());
		}
	}
};
