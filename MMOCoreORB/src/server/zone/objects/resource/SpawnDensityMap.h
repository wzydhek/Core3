/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file SpawnDensityMap.h
 * \author Kyle Burkhardt
 * \date 5-03-10
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "simplexnoise/SimplexNoise.h"

namespace server {
namespace zone {
namespace objects {
namespace resource {

/*
 * This class represents the Simplex Noise map of a resource
 */
class SpawnDensityMap : public Serializable {
protected:

	uint32 seed;  /// Random value to determine map shape
	float modifier; /// Value to determine map type (ore, or other)
	float density; /// Max density of map

	float minX, maxX, minY, maxY;

	uint32 totalUnits;  /// Total units that can be mined
	uint32 unitsHarvested;  /// Number of units already mined

public:
	enum {
		HIGHDENSITY   = 1,
		MEDIUMDENSITY = 2,
		LOWDENSITY    = 3
	};


public:
	SpawnDensityMap();

	SpawnDensityMap(const SpawnDensityMap& map);

	SpawnDensityMap(bool ore, short concentration, float minx, float maxx, float miny, float maxy);

	~SpawnDensityMap();

	friend void to_json(nlohmann::json& j, const SpawnDensityMap& m);

	SpawnDensityMap& operator=(const SpawnDensityMap& map);


	float getDensityAt(float x, float y) const;

	void print() const;

private:
	/**
	 * Initializes class
	 * \param ore Boolean value to see if map is ore
	 * \param concentration to determine density
	 */
	void initialize(bool ore, short concentration);

	/**
	 * Adds the variables needing to be serialized
	 */
	void addSerializableVariables();
};

} // namespace resource
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::resource;
