#include "NoBuildAreaMap.h"

NoBuildAreaMap::NoBuildAreaMap() {
}

NoBuildAreaMap::~NoBuildAreaMap() {
}

bool NoBuildAreaMap::add(Region* region) {
	return areas.add(region);
}

bool NoBuildAreaMap::isNoBuildZone(float x, float y, StringId& fullAreaName) {
	for (int i = 0; i < areas.size(); i++) {
		Region* region = areas.get(i);

		if (region->containsPoint(x, y)) {
			fullAreaName = *region->getObjectName();

			return true;
		}
	}

	return false;
}