/*
 * ChatRemoveModeratorFromRoomCallback.h
 *
 *  Created on: Feb 13, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatRemoveModeratorFromRoomCallback : public MessageCallback {
	String deopeeName; //Player to deop.
	String roomPath; //Room to deop the player in.
	int requestID;

public:
	ChatRemoveModeratorFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
