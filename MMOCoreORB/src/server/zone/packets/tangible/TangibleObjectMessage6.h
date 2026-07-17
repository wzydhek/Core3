/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace packets {
namespace tangible {

class TangibleObjectMessage6 : public BaseLineMessage {
public:
	TangibleObjectMessage6(const TangibleObject* tano, uint32 objType = 0x54414E4F, uint16 opcnt = 0x02);

	void insertDefenders(const TangibleObject* tano);

};

} // namespace tangible
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::tangible;
