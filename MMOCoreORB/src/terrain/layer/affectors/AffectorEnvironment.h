/*
 * AffectorEnvironment.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

class AffectorEnvironment : public ProceduralRule<'AENV'>, public AffectorProceduralRule {
	int environmentId;
	int var2;
	float weight;

public:
	AffectorEnvironment();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);

	void process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator);

	bool isEnabled();
};
