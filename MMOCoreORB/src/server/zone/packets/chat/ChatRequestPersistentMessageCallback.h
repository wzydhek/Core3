/*
 * ChatRequestPersistentMessageCallback.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatRequestPersistentMessageCallback : public MessageCallback {
	uint32 mailid;

public:
	ChatRequestPersistentMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
