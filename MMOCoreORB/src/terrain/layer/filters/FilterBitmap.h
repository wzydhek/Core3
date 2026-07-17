/*
 * FIlterBIT.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "FilterProceduralRule.h"

namespace terrain {

class TargaBitmap;

} // namespace terrain

using namespace terrain;

namespace terrain {
namespace layer {
namespace filters {

class FilterBitmap : public FilterProceduralRule {
	int bitmapId;
	//int featharingType;
	//float featheringAmount;
	float min;
	float max;

	TargaBitmap* map;

public:
	FilterBitmap();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);

	float process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator, FilterRectangle* rect);
};

} // namespace filters
} // namespace layer
} // namespace terrain

using namespace terrain::layer::filters;
