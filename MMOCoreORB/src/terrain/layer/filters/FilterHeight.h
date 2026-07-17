/*
 * FilterHeight.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "FilterProceduralRule.h"

namespace terrain {
namespace layer {
namespace filters {

class FilterHeight : public FilterProceduralRule {
	float minHeight;
	float maxHeight;

public:
	FilterHeight();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>);

	float process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator, FilterRectangle* rect);

};

} // namespace filters
} // namespace layer
} // namespace terrain

using namespace terrain::layer::filters;
