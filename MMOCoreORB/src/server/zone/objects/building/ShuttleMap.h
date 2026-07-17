/*
 * ShuttleMap.h
 *
 *  Created on: Aug 19, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/building/tasks/ShuttleDepartureTask.h"
#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace building {

class ShuttleMap : public VectorMap<uint64, Reference<ShuttleDepartureTask*> > {
public:
	ShuttleMap();
};

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;
