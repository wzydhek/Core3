/*
 * AffectorHeightConstant.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"

namespace terrain {

	class TerrainGenerator;

} // namespace terrain

using namespace terrain;

namespace terrain {
namespace layer {
namespace affectors {


class AffectorHeightConstant : public ProceduralRule<'AHCN'>, public AffectorProceduralRule {
	int operationType; // id?
	float height;

public:
	AffectorHeightConstant();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);

	void process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator);

	float getHeight();

	int getOperationType();

	void setHeight(float val);

	void setOperationType(int val);

	bool isEnabled();
};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
