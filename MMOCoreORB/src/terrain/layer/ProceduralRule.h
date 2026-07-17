/*
 * ProceduralRule.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../TemplateVariable.h"
#include "InformationHeader.h"

namespace terrain {
namespace layer {

template<int formType>
class ProceduralRule : public TemplateVariable<formType> {
protected:
	InformationHeader informationHeader;

public:
	ProceduralRule() : IffTemplateVariable() {

	}

	inline bool isEnabled() const {
		return informationHeader.isEnabled();
	}

};

} // namespace layer
} // namespace terrain

using namespace terrain::layer;
