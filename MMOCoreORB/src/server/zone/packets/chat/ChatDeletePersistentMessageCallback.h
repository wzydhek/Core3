/*
 * ChatDeletePersistentMessageCallback.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"
#include "server/chat/ChatManager.h"

class ChatDeletePersistentMessageCallback : public MessageCallback {
	uint32 mailid;

public:
	ChatDeletePersistentMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) :
		MessageCallback(client, server), mailid(0) {
	}

	void parse(Message* message) {
		mailid = message->parseInt();
	}

	void run() {
		ManagedReference<CreatureObject*> player = client->getPlayer();

		if (player == nullptr)
			return;

		ChatManager* chatManager = server->getChatManager();
		if (chatManager != nullptr)
			chatManager->deletePersistentMessage(player, mailid);
	}

};
