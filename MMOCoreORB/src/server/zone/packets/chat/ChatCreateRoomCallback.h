/*
 * ChatCreateRoomCallback.h
 *
 *  Created on: Oct 7, 2015
 *      Author: Anakis
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatCreateRoomCallback : public MessageCallback {
	uint8 moderationFlag; //0=not-moderated, 1=moderated
	uint8 permissionFlag; //0=private, 1=public
	String roomPath; //"SWG.Bria.group.281263685532.GroupChat.RoomName"
	String roomTitle;
	int requestID;
	short unknown;

public:
	ChatCreateRoomCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
