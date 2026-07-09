/*
 * RegionCenterPoint.h
 *
 *  Created on: 14/03/2010
 *      Author: victor
 */

#pragma once

#include "system/lang/Object.h"

class RegionCenterPoint : public Object {
public:
	float x, y, radius, radius2;

	RegionCenterPoint();

	RegionCenterPoint(float px, float py, float rad);

	RegionCenterPoint(const RegionCenterPoint& reg);

	RegionCenterPoint& operator=(const RegionCenterPoint& reg);

};
