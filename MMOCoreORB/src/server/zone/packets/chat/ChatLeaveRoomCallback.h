/*
 * ChatLeaveRoomCallback.h
 *
 *  Created on: Oct 11, 2015
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatLeaveRoomCallback : public MessageCallback {

	String roomPath;
	String leavingName;

public:
	ChatLeaveRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
