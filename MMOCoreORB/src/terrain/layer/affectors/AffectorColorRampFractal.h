/*
 * AffectorColorRampFractal.h
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

class AffectorColorRampFractal : public ProceduralRule<'ACRF'>, public AffectorProceduralRule {
	int familyId; // fractal family id
	byte var2;
	String shaderFile; // .tga

public:
	AffectorColorRampFractal();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);
};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
