/*
 * ChatAddModeratorToRoomCallback.h
 *
 *  Created on: Feb 16, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatAddModeratorToRoomCallback : public MessageCallback {
	String opeeName; //Player to op.
	String roomPath; //Room to op player in.
	int requestID;

public:
	ChatAddModeratorToRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
