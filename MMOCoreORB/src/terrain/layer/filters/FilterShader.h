/*
 * FilterShader.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "FilterProceduralRule.h"

namespace terrain {
namespace layer {
namespace filters {

class FilterShader : public FilterProceduralRule {
	int shaderId;

public:
	FilterShader();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);
};

} // namespace filters
} // namespace layer
} // namespace terrain

using namespace terrain::layer::filters;
