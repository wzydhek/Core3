/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "TangibleObjectMessage3.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"

namespace server {
namespace zone {
namespace packets {
namespace tangible {

class WeaponObjectMessage3 : public TangibleObjectMessage3 {
public:
	WeaponObjectMessage3(WeaponObject* weao);

};

} // namespace tangible
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::tangible;
