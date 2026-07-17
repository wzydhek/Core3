/*
 * ChatRemoveModeratorFromRoomCallback.h
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

class ChatRemoveModeratorFromRoomCallback : public MessageCallback {
	String deopeeName; //Player to deop.
	String roomPath; //Room to deop the player in.
	int requestID;

public:
	ChatRemoveModeratorFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
