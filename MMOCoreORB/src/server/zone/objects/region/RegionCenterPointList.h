/*
 * RegionCenterPointList.h
 *
 *  Created on: 14/03/2010
 *      Author: victor
 */

#pragma once

#include "RegionCenterPoint.h"
#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace region {

class RegionCenterPointList : public Vector<RegionCenterPoint> {
public:
	void addRegion(float x, float y, float radius);
};

} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region;
