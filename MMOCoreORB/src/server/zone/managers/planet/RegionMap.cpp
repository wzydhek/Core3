#include "RegionMap.h"

RegionMap::RegionMap() {
	cityRegions.setNoDuplicateInsertPlan();
	cityRegions.setNullValue(nullptr);

	regions.setNoDuplicateInsertPlan();
	regions.setNullValue(nullptr);

	setLoggingName("Region Map");
}

RegionMap::~RegionMap() {
}

void RegionMap::addCityRegion(CityRegion* cityRegion) {
	wlock();

	cityRegions.put(cityRegion->getCityRegionName(), cityRegion);

	unlock();
}

void RegionMap::dropCityRegion(const String& regionName) {
	wlock();

	cityRegions.drop(regionName);

	unlock();
}

void RegionMap::addRegion(Region* region) {
	wlock();

	regions.put(region->getAreaName(), region);

	unlock();
}

void RegionMap::dropRegion(const String& regionName) {
	wlock();

	regions.drop(regionName);

	unlock();
}

/**
 * Gets the first city region in the region map found at the specified coordinates.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @return Returns a city region or nullptr if one was not found.
 */
CityRegion* RegionMap::getCityRegionAt(float x, float y) {
	rlock();

	for (int i = 0; i < cityRegions.size(); ++i) {
		CityRegion* cityRegion = cityRegions.get(i);

		if (cityRegion->containsPoint(x, y)) {
			runlock();
			return cityRegion;
		}
	}

	runlock();

	return nullptr;
}

/**
 * Gets the first city region in the region map found at the specified coordinates.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @return Returns a city region or nullptr if one was not found.
 */
Region* RegionMap::getRegionAt(float x, float y) {
	rlock();

	for (int i = 0; i < regions.size(); ++i) {
		Region* region = regions.get(i);

		if (region->containsPoint(x, y)) {
			runlock();
			return region;
		}
	}

	runlock();

	return nullptr;
}

bool RegionMap::containsCityRegion(const String& name) {
	return cityRegions.contains(name);
}

bool RegionMap::containsRegion(const String& name) {
	return regions.contains(name);
}

CityRegion* RegionMap::getCityRegion(int index) {
	return cityRegions.get(index);
}

CityRegion* RegionMap::getCityRegion(const String& name) {
	return cityRegions.get(name);
}

int RegionMap::getTotalCityRegions() {
	return cityRegions.size();
}

Region* RegionMap::getRegion(int index) {
	return regions.get(index);
}

Region* RegionMap::getRegion(const String& name) {
	return regions.get(name);
}

int RegionMap::getTotalRegions() {
	return regions.size();
}