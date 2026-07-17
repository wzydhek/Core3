/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class EnterStructurePlacementModeMessage : public BaseMessage {
public:
	EnterStructurePlacementModeMessage(uint64 deedid, String crcpath);
};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
