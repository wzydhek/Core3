#include "RegionCenterPoint.h"

RegionCenterPoint::RegionCenterPoint() {
	x = 0, y = 0, radius = 0, radius2 = 0;
}

RegionCenterPoint::RegionCenterPoint(float px, float py, float rad) {
	x = px;
	y = py;
	radius = rad;
	radius2 = radius * radius;
}

RegionCenterPoint::RegionCenterPoint(const RegionCenterPoint& reg) : Object() {
	x = reg.x;
	y = reg.y;
	radius = reg.radius;
	radius2 = reg.radius2;
}

RegionCenterPoint& RegionCenterPoint::operator=(const RegionCenterPoint& reg) {
	if (this == &reg)
		return *this;

	x = reg.x;
	y = reg.y;
	radius = reg.radius;
	radius2 = reg.radius2;

	return *this;
}