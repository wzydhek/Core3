/*
 * ChatEnterRoomByIdCallback.h
 *
 *  Created on: Nov 5, 2010
 *      Author: oru
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatEnterRoomByIdCallback : public MessageCallback {
	uint32 requestID;
	uint32 roomID;

public:
	ChatEnterRoomByIdCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
