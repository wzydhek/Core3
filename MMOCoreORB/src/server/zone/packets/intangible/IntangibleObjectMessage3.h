/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/intangible/IntangibleObject.h"

namespace server {
namespace zone {
namespace packets {
namespace intangible {

class IntangibleObjectMessage3 : public BaseLineMessage {
public:
	IntangibleObjectMessage3(IntangibleObject* itno, uint32 objType = 0x4F4E5449, uint16 opcnt = 5);

};

} // namespace intangible
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::intangible;
