/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class GameSceneChangedMessage : public BaseMessage {
public:
	GameSceneChangedMessage() : BaseMessage(8) {
		insertShort(0x01);
		insertInt(0xBBADAEB9);
	}
	
};
