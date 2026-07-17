/*
 * ChatBanFromRoomCallback.h
 *
 *  Created on: Feb 18, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatBanFromRoomCallback : public MessageCallback {
	String baneeName; //Player to ban.
	String roomPath; //Room to ban the player from.
	int requestID;

public:
	ChatBanFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
