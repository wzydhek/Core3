/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/building/BuildingObject.h"

namespace server {
namespace zone {
namespace packets {
namespace building {

class BuildingObjectMessage6 : public BaseLineMessage {
public:
	BuildingObjectMessage6(BuildingObject *buio);
};

} // namespace building
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::building;
