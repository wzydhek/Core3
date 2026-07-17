/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/managers/planet/PlanetTravelPoint.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class EnterTicketPurchaseModeMessage : public BaseMessage {
public:
	EnterTicketPurchaseModeMessage(PlanetTravelPoint* ptp);
};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
