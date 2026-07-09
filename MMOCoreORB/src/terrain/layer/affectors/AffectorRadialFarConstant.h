/*
 * AffectorRadialFarConstant.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

class AffectorRadialFarConstant : public ProceduralRule<'AFDF'>, public AffectorProceduralRule {
	int familyId;
	int var2;
	int flag;
	int featheringType;
	float featheringAmount;

public:
	AffectorRadialFarConstant();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>);
};
