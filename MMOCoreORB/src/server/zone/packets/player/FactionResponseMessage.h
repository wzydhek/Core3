/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/player/variables/FactionStandingList.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class FactionResponseMessage : public BaseMessage {
public:

	FactionResponseMessage(FactionStandingList* fpl);
};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
