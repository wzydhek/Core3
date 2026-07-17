/*
 * ChatSendToRoomCallback.h
 *
 *  Created on: 30/12/2009
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatSendToRoomCallback : public MessageCallback {
	UnicodeString chatMessage;
	uint32 roomID;
	uint32 counter;

public:
	ChatSendToRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
