/*
 * RegionCenterPointList.h
 *
 *  Created on: 14/03/2010
 *      Author: victor
 */

#pragma once

#include "RegionCenterPoint.h"
#include "engine/engine.h"

class RegionCenterPointList : public Vector<RegionCenterPoint> {
public:
	void addRegion(float x, float y, float radius);
};
