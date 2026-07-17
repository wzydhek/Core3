/*
 * FilterProceduralRule.h
 *
 *  Created on: 21/12/2010
 *      Author: victor
 */

#pragma once

#include "../InformationHeader.h"

namespace terrain {

	class TerrainGenerator;

} // namespace terrain

using namespace terrain;

namespace terrain {
namespace layer {
namespace filters {

class FilterRectangle {
public:
	float minX, maxX, minY, maxY;
};

class FilterProceduralRule {
protected:
	InformationHeader informationHeader;

	int featheringType; // Feathering type? Leftover?
	float featheringAmount;
	int filterType;

	int internalType;
	const uint32 formType;

public:
	const static int HEIGHTTYPE = 0x100;
	const static int ENVIRONMENT = 0x200;

	const static int HEIGHT = 0;
	const static int FRACTAL = 1;
	const static int SLOPE = 2;
	const static int DIRECTION = 3;
	const static int SHADER = 4;
	const static int BITMAP = 5;

	FilterProceduralRule(int type, uint32 formType);

	virtual ~FilterProceduralRule();

	virtual float process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator, FilterRectangle* rect);

	void readObject(engine::util::IffStream* iffStream);

	virtual void parseFromIffStream(engine::util::IffStream* iffStream);

	bool isEnabled() const;

	int getFeatheringType() const;

	int getFilterType() const;

	int getInternalType() const;

	bool isType(int type) const;

};

} // namespace filters
} // namespace layer
} // namespace terrain

using namespace terrain::layer::filters;
