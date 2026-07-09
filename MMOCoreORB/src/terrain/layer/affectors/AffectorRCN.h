/*
 * AffectorRCN.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

class AffectorRCN : public ProceduralRule<'ARCN'>, public AffectorProceduralRule {
	int familyId;
	int var2;
	int flag; //add/remove
	int featheringType;
	float featheringAmount;

public:
	AffectorRCN();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>);
};
