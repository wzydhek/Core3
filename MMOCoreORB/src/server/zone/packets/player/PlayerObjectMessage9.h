/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class PlayerObjectMessage9 : public BaseLineMessage {
public:
	PlayerObjectMessage9(PlayerObjectImplementation* play);
};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
