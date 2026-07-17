/*
 * Boundary.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

namespace terrain {
	class ProceduralTerrainAppearance;
}

using namespace terrain;

#include "../ProceduralRule.h"

namespace terrain {
namespace layer {
namespace boundaries {

class Boundary {
protected:
	InformationHeader informationHeader;

	int featheringType = 0;
	float featheringAmount = 0;

	const uint32 formType;

public:
	Boundary(uint32 formType);

	virtual ~Boundary();

	virtual void executeRule(ProceduralTerrainAppearance* generator);

	void readObject(engine::util::IffStream* iffStream);

	virtual void parseFromIffStream(engine::util::IffStream* iffStream) = 0;


	virtual bool containsPoint(float x, float y) const = 0;

	virtual float checkInfluence(float x, float y) const = 0;

	virtual float getLocalWaterTableHeight() const;

	virtual float process(float x, float y) const = 0;

	int getFeatheringType() const;

	virtual float getMinX() const = 0;
	virtual float getMaxX() const = 0;
	virtual float getMinY() const = 0;
	virtual float getMaxY() const = 0;

	virtual void translateBoundary(float x, float y) = 0;

	bool isEnabled() const;
};

} // namespace boundaries
} // namespace layer
} // namespace terrain

using namespace terrain::layer::boundaries;
