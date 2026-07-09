/*
 * FilterSlope.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "FilterProceduralRule.h"

#define defaultValue 1.5707964

class FilterSlope : public FilterProceduralRule {
	float minAngle; // +32
	float max; // +40
	float maxAngle; // +28
	float min; //+36

	//const static float defaultValue = 1.5707964;

public:
	FilterSlope();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void setMinAngle(float newAngle);

	void setMaxAngle(float newAngle);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>);

	float process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator);

};
