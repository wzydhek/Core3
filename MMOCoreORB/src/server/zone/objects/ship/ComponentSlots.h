//
// Created by g on 12/31/17.
//

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class Components {
public:
	const static int CHASSIS = -1;

	enum ShipComponents : uint32 {
		REACTOR,
		ENGINE,
		SHIELD0,
		SHIELD1,
		ARMOR0,
		ARMOR1,
		CAPACITOR,
		BOOSTER,
		DROID_INTERFACE,
		BRIDGE,
		HANGAR,
		TARGETING_STATION,
		WEAPON_START
	};

	enum ShipComponentsMax {
		FIGHTERSLOTMAX = 19,
		CAPITALSLOTMAX = 111,
		SIZE = 112
	};

	static String shipComponentSlotToString(int slot);
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
