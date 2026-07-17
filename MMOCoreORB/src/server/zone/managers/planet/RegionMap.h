/*
 * RegionMap.h
 *
 *  Created on: 30/01/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/objects/region/Region.h"

namespace server {
namespace zone {
namespace managers {
namespace planet {

class RegionMap : public ReadWriteLock, public Object, public Logger {
	VectorMap<String, ManagedReference<CityRegion*> > cityRegions;

	VectorMap<String, ManagedReference<Region*> > regions;

public:
	RegionMap();

	~RegionMap();

	void addCityRegion(CityRegion* cityRegion);

	void dropCityRegion(const String& regionName);

	void addRegion(Region* region);

	void dropRegion(const String& regionName);

	/**
	 * Gets the first city region in the region map found at the specified coordinates.
	 * @param x The x coordinate.
	 * @param y The y coordinate.
	 * @return Returns a city region or nullptr if one was not found.
	 */
	CityRegion* getCityRegionAt(float x, float y);

	/**
	 * Gets the first city region in the region map found at the specified coordinates.
	 * @param x The x coordinate.
	 * @param y The y coordinate.
	 * @return Returns a city region or nullptr if one was not found.
	 */
	Region* getRegionAt(float x, float y);

	bool containsCityRegion(const String& name);

	bool containsRegion(const String& name);

	CityRegion* getCityRegion(int index);

	CityRegion* getCityRegion(const String& name);

	int getTotalCityRegions();

	Region* getRegion(int index);

	Region* getRegion(const String& name);

	int getTotalRegions();
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;
