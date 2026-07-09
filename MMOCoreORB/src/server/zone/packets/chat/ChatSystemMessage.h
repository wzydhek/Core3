/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/chat/StringIdChatParameter.h"

class ChatSystemMessage : public BaseMessage {

public:
	enum {
		DISPLAY_CHATANDSCREEN = 0x00,
		DISPLAY_CHATONLY      = 0x02
	};

public:
	ChatSystemMessage(const UnicodeString& message, byte displayType = DISPLAY_CHATANDSCREEN);

	ChatSystemMessage(StringIdChatParameter& sid, byte displayType = DISPLAY_CHATANDSCREEN);
};
