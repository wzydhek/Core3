/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnGetIgnoreList : public BaseMessage {
public:
	ChatOnGetIgnoreList(PlayerObject* ghost);
};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
