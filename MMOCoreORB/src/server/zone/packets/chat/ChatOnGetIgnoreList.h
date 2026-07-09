/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class ChatOnGetIgnoreList : public BaseMessage {
public:
	ChatOnGetIgnoreList(PlayerObject* ghost);
};
