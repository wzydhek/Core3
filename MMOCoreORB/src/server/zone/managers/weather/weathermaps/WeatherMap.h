/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file WeatherMap.h
 * \author Kyle Burkhardt
 * \date 2-10-12
 */

#pragma once

#include "server/zone/objects/resource/simplexnoise/SimplexNoise.h"
#include "system/io/Serializable.h"
#include "system/lang/Object.h"

namespace server {
namespace zone {
namespace managers {
namespace weather {
namespace weathermaps {

/*
 * This class represents the Simplex Noise map of planetary weather
 */
class WeatherMap : public Serializable {
protected:

	uint32 seed;  /// Random value to determine map shape
	float modifier; /// Value to determine map type (ore, or other)
	float density; /// Max density of map
	uint64 startTime;
	uint64 endTime;

	float minX, maxX, minY, maxY;

public:
	WeatherMap();

	WeatherMap(const WeatherMap& map);

	WeatherMap(int weatherStability, float minx, float maxx, float miny, float maxy, int stop);

	~WeatherMap();

	WeatherMap& operator=(const WeatherMap& map);


	byte getWeatherAt(float x, float y);

	uint64 getEndTime();

	String printInfo(float x, float y);

private:
	/**
	 * Initializes class
	 * \param stormIntensity to determine storm intensity
	 */
	void initialize(short weatherStability);

	/**
	 * Adds the variables needing to be serialized
	 */
	void addSerializableVariables();
};

} // namespace weathermaps
} // namespace weather
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::weather::weathermaps;
