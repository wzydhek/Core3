/*
 * AffectorHeightTerrace.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

namespace terrain {
namespace layer {
namespace affectors {

class AffectorHeightTerrace : public ProceduralRule<'AHTR'>, public AffectorProceduralRule {
	float flatRatio;
	float height;

public:
	AffectorHeightTerrace();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0004'>);

	void process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator);

	bool isEnabled();
};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
