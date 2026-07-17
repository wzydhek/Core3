/*
 * CurrentFoundPath.h
 *
 *  Created on: 28/01/2013
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"

#include "server/zone/objects/scene/WorldCoordinates.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace variables {

class CurrentFoundPath : public Vector<WorldCoordinates> {

};

} // namespace variables
} // namespace ai
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::ai::variables;
