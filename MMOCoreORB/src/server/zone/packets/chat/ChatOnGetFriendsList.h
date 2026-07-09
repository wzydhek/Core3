/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class ChatOnGetFriendsList : public BaseMessage {
public:
	ChatOnGetFriendsList(PlayerObject* ghost);

};
