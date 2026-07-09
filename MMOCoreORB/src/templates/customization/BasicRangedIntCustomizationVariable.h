/*
 * BasicRangedIntCustomizationVariable.h
 *
 *  Created on: 01/04/2011
 *      Author: victor
 */

#pragma once

#include "templates/params/RangedIntCustomizationVariable.h"

class BasicRangedIntCustomizationVariable : public RangedIntCustomizationVariable {

public:
	BasicRangedIntCustomizationVariable(int min, int max, int def);

	BasicRangedIntCustomizationVariable(const BasicRangedIntCustomizationVariable& m);

	int getMinValueInclusive();

	int getMaxValueExclusive();

	int getDefaultValue();
};
