/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnReceiveRoomInvitation : public BaseMessage {
public:
	ChatOnReceiveRoomInvitation(const String& galaxy, const String& moderator, const String& roomPath);

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
