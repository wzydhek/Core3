/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnSendInstantMessage : public BaseMessage {
public:
	ChatOnSendInstantMessage(uint32 seq, int result = 0); 
	
};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
