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

class IntangibleObjectMessage6 : public BaseLineMessage {
public:
	IntangibleObjectMessage6(IntangibleObject* itno);
};

} // namespace intangible
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::intangible;
