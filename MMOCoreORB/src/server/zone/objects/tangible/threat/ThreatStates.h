/*
 * ThreatStates.h
 *
 *  Created on: 1/20/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace threat {

class ThreatStates {
public:
	/// Normal States 0x01, 0x02 etc

	/// Unique States 0x101 0x102
	/// Only one of these can exist
	/// in the map at a time
	const static int UNIQUESTATE = 0x100;
	const static int TAUNTED = 0x101;
	const static int FOCUSED = 0x102;
};

} // namespace threat
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::threat;
