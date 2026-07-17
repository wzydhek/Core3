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

class TangibleObjectMessage7 : public BaseLineMessage {
public:
	TangibleObjectMessage7(const TangibleObject* tano);

};

} // namespace tangible
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::tangible;
