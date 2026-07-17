/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/factorycrate/FactoryCrate.h"

namespace server {
namespace zone {
namespace packets {
namespace factory {

class FactoryCrateObjectDeltaMessage3 : public DeltaMessage {
	FactoryCrate* tano;

public:
	FactoryCrateObjectDeltaMessage3(FactoryCrate* ta, uint32 objType = 0x46435954);

	void setQuantity(int quantity);
};

} // namespace factory
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::factory;
