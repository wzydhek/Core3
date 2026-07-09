/*
 * ChatUnbanFromRoomCallback.h
 *
 *  Created on: Feb 19, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatUnbanFromRoomCallback : public MessageCallback {
	String unbaneeName; //Player to unban.
	String roomPath; //Room to unban player from.
	int requestID;

public:
	ChatUnbanFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
