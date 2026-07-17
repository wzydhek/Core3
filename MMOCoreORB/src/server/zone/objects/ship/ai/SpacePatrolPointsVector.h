/*
 * SpacePatrolPointsVector.h
 */

#pragma once

#include "engine/engine.h"
#include "SpacePatrolPoint.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {

class SpacePatrolPointsVector : public Vector<SpacePatrolPoint> {

};

} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai;
