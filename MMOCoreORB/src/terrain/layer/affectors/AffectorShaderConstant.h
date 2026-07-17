/*
 * AffectorShaderConstant.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

namespace terrain {
namespace layer {
namespace affectors {

class AffectorShaderConstant : public ProceduralRule<'ASCN'>, public AffectorProceduralRule {
	int familyId; // shader family id to affect
	int featheringType;
	float featheringAmount; // how much to soften

public:
	AffectorShaderConstant();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);
};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
