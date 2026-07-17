/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace packets {
namespace factory {

class FactoryCrateObjectMessage6 : public BaseLineMessage {
public:
	FactoryCrateObjectMessage6(TangibleObject* tano);
	
};

} // namespace factory
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::factory;
