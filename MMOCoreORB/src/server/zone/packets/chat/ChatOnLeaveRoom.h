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

class ChatOnLeaveRoom : public BaseMessage {
public:

	ChatOnLeaveRoom(ChatRoom* room, CreatureObject* player);
};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
