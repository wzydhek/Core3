/*
 * ChatUninviteFromRoomCallback.h
 *
 *  Created on: Feb 13, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatUninviteFromRoomCallback : public MessageCallback {
	String uninviteeName; //Player to uninvite.
	String roomPath; //Room to uninvite player from.
	int requestID;

public:
	ChatUninviteFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
