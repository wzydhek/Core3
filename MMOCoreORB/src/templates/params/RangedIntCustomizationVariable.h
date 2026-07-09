/*
 * RangedIntCustomizationVariable.h
 *
 *  Created on: 16-abr-2009
 *      Author: TheAnswer
 */

#pragma once

#include "templates/params/Param.h"
#include "templates/params/primitives/StringParam.h"
#include "templates/params/primitives/IntegerParam.h"
#include "templates/customization/CustomizationVariable.h"


class RangedIntCustomizationVariable : public CustomizationVariable, public Param {
protected:
	StringParam variableName;
	IntegerParam minValueInclusive;
	IntegerParam defaultValue;
	IntegerParam maxValueExclusive;

public:
	RangedIntCustomizationVariable();

	RangedIntCustomizationVariable(const RangedIntCustomizationVariable& m);

	RangedIntCustomizationVariable& operator=(const RangedIntCustomizationVariable& m);

	~RangedIntCustomizationVariable();

	int getDefaultValue() const;

	String toString() const;

	bool parse(Chunk* source);

	const String& getVariableName() const;

};
