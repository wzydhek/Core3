#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class ShipDroidData {
public:
	enum DroidType : int {
			NONE = 0,
			ASTROMECH = 1,
			FLIGHTCOMPUTER = 2
	};

	static uint32 getShipDroidType(uint32 shipNameCRC);

	static uint32 getDroidType(uint32 droidCrc);
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
