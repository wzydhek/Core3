/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage3.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace creature {

class CreatureObjectMessage3 : public TangibleObjectMessage3 {
public:
	CreatureObjectMessage3(CreatureObject* creo);

};

} // namespace creature
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::creature;
