/*
 *  HeightData.h
 *
 *  Created on: 31/01/2010
 *  Author: victor
 */

#pragma once

#include "../TemplateVariable.h"
#include "Segment.h"

// #define DEBUG_AFFECTOR_ROAD

namespace terrain {
namespace layer {

class HeightData : public TemplateVariable<'HDTA'> {
	Vector<Segment*> segments;

public:
	HeightData();

	~HeightData();

	void parseFromIffStream(engine::util::IffStream* iffStream);
	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);
	void findNearestHeight(float& baseValue, Vector3 worldPosition, Vector3 roadStart, Vector3 roadCenter, float direction);
};

} // namespace layer
} // namespace terrain

using namespace terrain::layer;
