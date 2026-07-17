/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/intangible/IntangibleObjectMessage3.h"
#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class PlayerObjectMessage3 : public IntangibleObjectMessage3 {
public:
	PlayerObjectMessage3(PlayerObject* ghost);

};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
