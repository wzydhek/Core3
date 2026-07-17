/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnChangeIgnoreStatus : public BaseMessage {
public:
	ChatOnChangeIgnoreStatus(uint64 oid, const String& name, const String& server, bool add);

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
