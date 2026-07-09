/*
 * AffectorRadialConstant.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

class AffectorRadialConstant : public ProceduralRule<'AFDN'>, public AffectorProceduralRule {
	int familyId;
	int var2;
	int flag; // add/remove
	int featheringType;
	float featheringAmount;

public:
	AffectorRadialConstant();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>);
};
