/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage6.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace creature {

class CreatureObjectMessage6 : public TangibleObjectMessage6 {
public:
	CreatureObjectMessage6(const CreatureObject* creo);

	void insertEquipmentList(const CreatureObject* creo);
};

} // namespace creature
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::creature;
