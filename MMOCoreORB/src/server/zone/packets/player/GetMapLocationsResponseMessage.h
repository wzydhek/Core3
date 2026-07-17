/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/managers/planet/MapLocationTable.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class GetMapLocationsResponseMessage : public BaseMessage {
public:
	GetMapLocationsResponseMessage(const String& planet, const MapLocationTable* mapLocations, CreatureObject* player);

};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
