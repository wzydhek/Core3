/*
 * AffectorShaderReplace.h
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

class AffectorShaderReplace : public ProceduralRule<'ASRP'>, public AffectorProceduralRule {
	int oldShaderId;
	int newShaderId;
	int featheringType;
	float featheringAmount;

public:
	AffectorShaderReplace();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);
};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
