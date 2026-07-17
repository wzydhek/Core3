/*
 * AffectorHeightFractal.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

namespace terrain {

	class TerrainGenerator;
	class MapFractal;

} // namespace terrain

using namespace terrain;

namespace terrain {
namespace layer {
namespace affectors {

class AffectorHeightFractal : public ProceduralRule<'AHFR'>, public AffectorProceduralRule {
	int fractalId; // fractal group id in MGRP
	int operationType;
	float height;
	MapFractal* mfrc;

public:
	AffectorHeightFractal();

	void process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator);

	void parseFromIffStream(engine::util::IffStream* iffStream);
	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0003'>);

	int getFractalId();

	float getHeight();

	bool isEnabled();
};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
