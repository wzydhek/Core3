/*
 * ChatBanFromRoomCallback.h
 *
 *  Created on: Feb 18, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatBanFromRoomCallback : public MessageCallback {
	String baneeName; //Player to ban.
	String roomPath; //Room to ban the player from.
	int requestID;

public:
	ChatBanFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
