/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatOnDestroyRoom : public BaseMessage {
public:

	ChatOnDestroyRoom(const String& game, const String& server, const String& owner, uint32 roomID, int errorCode = 0, int requestID = 0);

	ChatOnDestroyRoom(uint32 roomID, int errorCode, int requestID);

};
