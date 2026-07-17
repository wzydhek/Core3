/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/chat/StringIdChatParameter.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

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

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
