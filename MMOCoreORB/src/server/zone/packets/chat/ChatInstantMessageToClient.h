/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatInstantMessageToClient : public BaseMessage {
public:
	ChatInstantMessageToClient(const String& game, const String& galaxy, const String& name, const UnicodeString& message);
	
};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
