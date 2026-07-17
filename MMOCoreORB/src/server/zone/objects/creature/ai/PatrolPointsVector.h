/*
 * PatrolPointsVector.h
 *
 *  Created on: 11/07/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "PatrolPoint.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {

class PatrolPointsVector : public Vector<PatrolPoint> {

};

} // namespace ai
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::ai;
