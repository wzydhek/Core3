/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/mission/MissionObject.h"

namespace server {
namespace zone {
namespace packets {
namespace mission {

class MissionObjectMessage6 : public BaseLineMessage {
public:
	MissionObjectMessage6(MissionObject* mi);
};

} // namespace mission
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::mission;
