#include "WeatherMap.h"

WeatherMap::WeatherMap() : Object(), Serializable() {
	addSerializableVariables();
}

WeatherMap::WeatherMap(const WeatherMap& map) : Object(), Serializable() {
	seed = map.seed;
	modifier = map.modifier;
	density = map.density;
	startTime = map.startTime;
	endTime = map.endTime;
	minX = map.minX;
	maxX = map.maxX;
	minY = map.minY;
	maxY = map.maxY;

	addSerializableVariables();
}

WeatherMap::WeatherMap(int weatherStability, float minx, float maxx, float miny, float maxy, int stop) : Object(), Serializable() {
	initialize(weatherStability);
	minX = minx;
	maxX = maxx;
	minY = miny;
	maxY = maxy;

	endTime = time(0) + stop;
}

WeatherMap::~WeatherMap() {
}

WeatherMap& WeatherMap::operator=(const WeatherMap& map) {
	if (this == &map)
		return *this;

	seed = map.seed;
	modifier = map.modifier;
	density = map.density;
	minX = map.minX;
	maxX = map.maxX;
	minY = map.minY;
	maxY = map.maxY;
	startTime = map.startTime;
	endTime = map.endTime;

	return *this;
}

byte WeatherMap::getWeatherAt(float x, float y) {
	if (time(0) > endTime || time(0) < startTime)
		return 0;

	float current = time(0) - startTime; // cannot be negative
	float end = endTime - startTime;
	float mid = end / 2.f;

	if (current > mid)
		current = end - current;

	float currentDensity = (current / mid) * density;
	x -= minX;
	y = maxY - y;

	// [0,1]
	float value = (SimplexNoise::noise(x * modifier, y * modifier, seed * modifier) + 1) / 2.0f;

	byte weather = (byte)(((value * currentDensity) * 100) / 20.f);

	return weather;
}

uint64 WeatherMap::getEndTime() {
	return endTime;
}

String WeatherMap::printInfo(float x, float y) {
	float current = time(0) - startTime;
	float end = endTime - startTime;
	float mid = end / 2.f;

	if (current > mid)
		current = end - current;

	float currentDensity = (current / mid) * density;
	x -= minX;
	y = maxY - y;

	// [0,1]
	float value = (SimplexNoise::noise(x * modifier, y * modifier, seed * modifier) + 1) / 2.0f;

	StringBuffer valueString;
	valueString << "Density: " << density << " Density: "
				<< currentDensity
				//<< " Value: " << String::valueOf(value)
				<< " Equation: " << String::valueOf((((value * currentDensity) * 100) / 20.f)) << " Weather: " << String::valueOf((byte)(((value * currentDensity) * 100) / 20.f)) << " Seed: " << seed << " time: " << time(0) - startTime << "/" << endTime - startTime;

	return valueString.toString();
}

/**
 * Initializes class
 * \param stormIntensity to determine storm intensity
 */
void WeatherMap::initialize(short weatherStability) {
	startTime = time(0);
	seed = System::random(startTime);

	modifier = .00017f;

	if (System::random(100) > weatherStability) {
		density = (System::random(30) + 60) / 100.0f;
	} else {
		density = (System::random(100 - weatherStability + 30) + 20) / 100.0f;
	}

	if (density > 1)
		density = 1;
	if (density < 0)
		density = 0;

	addSerializableVariables();
}

/**
 * Adds the variables needing to be serialized
 */
void WeatherMap::addSerializableVariables() {
	addSerializableVariable("seed", &seed);
	addSerializableVariable("modifier", &modifier);
	addSerializableVariable("density", &density);
	addSerializableVariable("minX", &minX);
	addSerializableVariable("maxX", &maxX);
	addSerializableVariable("minY", &minY);
	addSerializableVariable("maxY", &maxY);
	addSerializableVariable("startTime", &startTime);
	addSerializableVariable("endTime", &endTime);
}