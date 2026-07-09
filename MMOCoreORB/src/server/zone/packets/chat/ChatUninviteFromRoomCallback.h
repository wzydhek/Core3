/*
 * ChatUninviteFromRoomCallback.h
 *
 *  Created on: Feb 13, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatUninviteFromRoomCallback : public MessageCallback {
	String uninviteeName; //Player to uninvite.
	String roomPath; //Room to uninvite player from.
	int requestID;

public:
	ChatUninviteFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
