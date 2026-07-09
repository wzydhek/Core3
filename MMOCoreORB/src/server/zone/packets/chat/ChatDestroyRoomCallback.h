/*
 * ChatDestroyRoomCallback.h
 *
 *  Created on: Oct 11, 2015
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatDestroyRoomCallback : public MessageCallback {
	int roomID;
	int requestID;

public:
	ChatDestroyRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
