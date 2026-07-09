/*
 * AffectorFloraNonCollidableConstant.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

class AffectorFloraNonCollidableConstant : public ProceduralRule<'AFSN'>, public AffectorProceduralRule {
	int familyId;
	int var2;
	int flag; //add/remove
	int featheringType;
	float featheringAmount;

public:
	AffectorFloraNonCollidableConstant();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0004'>);
};
