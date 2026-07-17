/*
 * ChatUnbanFromRoomCallback.h
 *
 *  Created on: Feb 19, 2016
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatUnbanFromRoomCallback : public MessageCallback {
	String unbaneeName; //Player to unban.
	String roomPath; //Room to unban player from.
	int requestID;

public:
	ChatUnbanFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
