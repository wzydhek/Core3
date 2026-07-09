/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatOnEnteredRoom : public BaseMessage {
public:
	ChatOnEnteredRoom(const String& galaxy, const String& playername, uint32 roomID, int error, int requestID);

};
