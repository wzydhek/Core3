/*
 * SpaceRegionMap.h
 *
 *	Created on: 30/01/2010
 *	Author: victor
 */

#pragma once

#include "server/zone/objects/region/space/SpaceRegion.h"

class SpaceRegionMap : public ReadWriteLock, public Object, public Logger {
	VectorMap<String, ManagedReference<SpaceRegion*> > regions;

public:
	SpaceRegionMap();

	~SpaceRegionMap();

	void addRegion(SpaceRegion* region);

	void dropRegion(const String& regionName);

	/**
	 * Gets the first region in the region map found at the specified coordinates.
	 * @param x The x coordinate.
	 * @param y The y coordinate.
	 * @return Returns a city region or nullptr if one was not found.
	 */
	SpaceRegion* getRegionAt(float x, float y);

	bool containsRegion(const String& name);

	SpaceRegion* getRegion(int index);

	SpaceRegion* getRegion(const String& name);

	int getTotalRegions();
};
