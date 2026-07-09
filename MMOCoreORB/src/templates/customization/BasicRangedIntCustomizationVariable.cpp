#include "BasicRangedIntCustomizationVariable.h"

BasicRangedIntCustomizationVariable::BasicRangedIntCustomizationVariable(int min, int max, int def) {
	minValueInclusive = min;
	maxValueExclusive = max;
	defaultValue = def;
}

BasicRangedIntCustomizationVariable::BasicRangedIntCustomizationVariable(const BasicRangedIntCustomizationVariable& m) : RangedIntCustomizationVariable(m) {
}

int BasicRangedIntCustomizationVariable::getMinValueInclusive() {
	return minValueInclusive;
}

int BasicRangedIntCustomizationVariable::getMaxValueExclusive() {
	return maxValueExclusive;
}

int BasicRangedIntCustomizationVariable::getDefaultValue() {
	return defaultValue;
}