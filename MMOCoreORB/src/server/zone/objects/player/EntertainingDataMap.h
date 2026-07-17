/*
 * EntertainingDataMap.h
 *
 *  Created on: 22/09/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "EntertainingData.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class EntertainingDataMap : public VectorMap<ManagedReference<CreatureObject*>, EntertainingData > {

};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;
