/*
 * ChatInviteToRoomCallback.h
 *
 *  Created on: Feb 11, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatInviteToRoomCallback : public MessageCallback {
	String inviteeName; //Player to invite.
	String roomPath; //Room to invite player to.
	int requestID;

public:
	ChatInviteToRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
