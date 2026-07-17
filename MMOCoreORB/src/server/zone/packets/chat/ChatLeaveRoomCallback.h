/*
 * ChatLeaveRoomCallback.h
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

class ChatLeaveRoomCallback : public MessageCallback {

	String roomPath;
	String leavingName;

public:
	ChatLeaveRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
