#include "SpaceRegionMap.h"

SpaceRegionMap::SpaceRegionMap() {
	regions.setNoDuplicateInsertPlan();
	regions.setNullValue(nullptr);

	setLoggingName("SpaceRegionMap");
}

SpaceRegionMap::~SpaceRegionMap() {
}

void SpaceRegionMap::addRegion(SpaceRegion* region) {
	wlock();

	regions.put(region->getAreaName(), region);

	unlock();
}

void SpaceRegionMap::dropRegion(const String& regionName) {
	wlock();

	regions.drop(regionName);

	unlock();
}

/**
 * Gets the first region in the region map found at the specified coordinates.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @return Returns a city region or nullptr if one was not found.
 */
SpaceRegion* SpaceRegionMap::getRegionAt(float x, float y) {
	rlock();

	for (int i = 0; i < regions.size(); ++i) {
		SpaceRegion* region = regions.get(i);

		if (region->containsPoint(x, y)) {
			runlock();
			return region;
		}
	}

	runlock();

	return nullptr;
}

bool SpaceRegionMap::containsRegion(const String& name) {
	return regions.contains(name);
}

SpaceRegion* SpaceRegionMap::getRegion(int index) {
	return regions.get(index);
}

SpaceRegion* SpaceRegionMap::getRegion(const String& name) {
	return regions.get(name);
}

int SpaceRegionMap::getTotalRegions() {
	return regions.size();
}