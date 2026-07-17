/*
 * AffectorColorRampHeight.h
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

class AffectorColorRampHeight : public ProceduralRule<'ACRH'>, public AffectorProceduralRule {
	int familyId;
	float min;
	float max;

	String shaderFile; //.tga

public:
	AffectorColorRampHeight();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);
};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
