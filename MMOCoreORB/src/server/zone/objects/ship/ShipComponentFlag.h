/*
 * ShipComponentFlag.h
 *
 * Author: H
 */

#pragma once

namespace server {
namespace zone {
namespace objects {
namespace ship {

namespace ShipComponentFlag {
	enum {
		DISABLED				= 0x0001,
		LOW_POWER				= 0x0002,
		ACTIVE					= 0x0004,
		DEMOLISHED				= 0x0008,
		REVERSE_ENGINEERED		= 0x0010,
		SHIELD_FRONT			= 0x0020,
		SHIELD_BACK				= 0x0040,
		DISABLED_NEEDS_POWER	= 0x0080
	};
}

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
