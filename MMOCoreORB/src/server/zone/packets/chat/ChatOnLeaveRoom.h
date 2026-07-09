/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/chat/room/ChatRoom.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ChatOnLeaveRoom : public BaseMessage {
public:

	ChatOnLeaveRoom(ChatRoom* room, CreatureObject* player);
};
