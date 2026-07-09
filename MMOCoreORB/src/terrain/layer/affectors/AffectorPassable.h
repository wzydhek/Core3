/*
 * AffectorPAS.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

class AffectorPassable : public ProceduralRule<'APAS'>, public AffectorProceduralRule {
	float var1, var2;

public:
	AffectorPassable();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);
};
