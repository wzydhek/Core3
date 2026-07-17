/*
 * ChatInviteToRoomCallback.h
 *
 *  Created on: Feb 11, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatInviteToRoomCallback : public MessageCallback {
	String inviteeName; //Player to invite.
	String roomPath; //Room to invite player to.
	int requestID;

public:
	ChatInviteToRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
