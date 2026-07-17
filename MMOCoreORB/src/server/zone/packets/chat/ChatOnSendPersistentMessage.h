/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

//Mail

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnSendPersistentMessage : public BaseMessage {
public:
	ChatOnSendPersistentMessage(uint32 seq, int returnCode);
	
};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
