/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/chat/room/ChatRoom.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnCreateRoom : public BaseMessage {
public:

	ChatOnCreateRoom(ChatRoom* room, int requestID, int error);

	void addToModeratorList(ChatRoom* room);
	
	void addToUserList(ChatRoom* room);

	ChatOnCreateRoom(CreatureObject* player, int requestID, int error);

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
