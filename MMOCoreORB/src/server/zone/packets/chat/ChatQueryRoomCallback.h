/*
 * ChatQueryRoomCallback.h
 *
 *  Created on: Oct 10, 2015
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatQueryRoomCallback : public MessageCallback {
	int requestID;
	String roomPath;


public:
	ChatQueryRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
