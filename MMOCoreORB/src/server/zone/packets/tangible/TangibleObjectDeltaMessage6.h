/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace packets {
namespace tangible {

class TangibleObjectDeltaMessage6 : public DeltaMessage {
	TangibleObject* tano;

public:
	TangibleObjectDeltaMessage6(TangibleObject* ta, uint32 objType = 0x54414E4F);

};

} // namespace tangible
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::tangible;
