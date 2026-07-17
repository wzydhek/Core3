/*
 * ChatDestroyRoomCallback.h
 *
 *  Created on: Oct 11, 2015
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatDestroyRoomCallback : public MessageCallback {
	int roomID;
	int requestID;

public:
	ChatDestroyRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
