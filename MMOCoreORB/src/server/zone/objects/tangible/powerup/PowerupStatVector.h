/*
 * PowerupStatVector.h
 *
 *  Created on: Mar 06, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/tangible/PowerupStat.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace powerup {

class PowerupStatVector : public Vector<PowerupStat> {
public:
};

} // namespace powerup
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::powerup;
