/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatRoomMessage : public BaseMessage {
public:
	ChatRoomMessage(const String& sender, const String& galaxyName, const UnicodeString& message, uint32 channelid);

};
