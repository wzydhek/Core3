/*
 * AffectorHeightTerrace.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

class AffectorHeightTerrace : public ProceduralRule<'AHTR'>, public AffectorProceduralRule {
	float flatRatio;
	float height;

public:
	AffectorHeightTerrace();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0004'>);

	void process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator);

	bool isEnabled();
};
