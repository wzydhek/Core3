/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnEnteredRoom : public BaseMessage {
public:
	ChatOnEnteredRoom(const String& galaxy, const String& playername, uint32 roomID, int error, int requestID);

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
