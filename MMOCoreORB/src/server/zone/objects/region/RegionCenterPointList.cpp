#include "RegionCenterPointList.h"

void RegionCenterPointList::addRegion(float x, float y, float radius) {
	RegionCenterPoint point(x, y, radius);
	add(point);
}