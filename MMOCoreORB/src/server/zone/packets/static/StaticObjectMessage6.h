/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/staticobject/StaticObject.h"

namespace server {
namespace zone {
namespace packets {
namespace _static {

class StaticObjectMessage6 : public BaseLineMessage {
public:
	StaticObjectMessage6(StaticObject* stao);
	
};

} // namespace _static
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::_static;
