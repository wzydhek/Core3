/*
 * FIlterFractal.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "FilterProceduralRule.h"

namespace terrain {

class TerrainGenerator;
class MapFractal;

} // namespace terrain

using namespace terrain;

namespace terrain {
namespace layer {
namespace filters {

class FilterFractal : public FilterProceduralRule {
	int fractalId; // Fractal Group ID to modify (MGRP)
	float min;
	float max; // Scale/Stepping?
	float var6; // Scale/Stepping?
	MapFractal* mfrc;

public:
	FilterFractal();

	void parseFromIffStream(engine::util::IffStream* iffStream);
	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0005'>);

	float process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator, FilterRectangle* rect);
};

} // namespace filters
} // namespace layer
} // namespace terrain

using namespace terrain::layer::filters;
