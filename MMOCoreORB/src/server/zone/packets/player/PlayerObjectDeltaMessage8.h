/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class PlayerObjectDeltaMessage8 : public DeltaMessage {
	PlayerObjectImplementation* play;

public:
	PlayerObjectDeltaMessage8(PlayerObjectImplementation* pl);

	void updateForcePower();

	void updateForcePowerMax();
};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
