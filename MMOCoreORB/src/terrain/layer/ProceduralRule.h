/*
 * ProceduralRule.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../TemplateVariable.h"
#include "InformationHeader.h"

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
