/*
 * ChatSendToRoomCallback.h
 *
 *  Created on: 30/12/2009
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatSendToRoomCallback : public MessageCallback {
	UnicodeString chatMessage;
	uint32 roomID;
	uint32 counter;

public:
	ChatSendToRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
