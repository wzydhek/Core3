/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

//Mail - "You got mail"
//ChatOnConnectAvatar

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnConnectAvatar : public BaseMessage {
public:
	ChatOnConnectAvatar();
	
};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
