/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatRoomMessage : public BaseMessage {
public:
	ChatRoomMessage(const String& sender, const String& galaxyName, const UnicodeString& message, uint32 channelid);

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
