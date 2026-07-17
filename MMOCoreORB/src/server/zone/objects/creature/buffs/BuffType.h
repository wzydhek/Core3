/*
 * BuffType.h
 *
 *  Created on: 03/06/2010
 *      Author: victor
 */

#pragma once

#include "../BuffAttribute.h"
#include "BuffCRC.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class BuffType {
public:
	enum {
		OTHER,
		FOOD,
		MEDICAL,
		PERFORMANCE,
		SPICE,
		SKILL,
		JEDI,
		INNATE,
		STATE,
		TRAP
	};
};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;
