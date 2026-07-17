/*
 * AffectorFCN.h
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

class AffectorFCN : public ProceduralRule<'AFCN'>, public AffectorProceduralRule {
	int familyId;
	int var2;
	int flag; //add/remove
	int featheringType;
	float featheringAmount;

public:
	AffectorFCN();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0004'>);
};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
