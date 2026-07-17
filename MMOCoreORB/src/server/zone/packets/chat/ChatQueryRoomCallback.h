/*
 * ChatQueryRoomCallback.h
 *
 *  Created on: Oct 10, 2015
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatQueryRoomCallback : public MessageCallback {
	int requestID;
	String roomPath;


public:
	ChatQueryRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
