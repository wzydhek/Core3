#include "RangedIntCustomizationVariable.h"

RangedIntCustomizationVariable::RangedIntCustomizationVariable() : Param() {
	setType(RANGEDINTCUSTOMIZATIONVARIABLE);
}

RangedIntCustomizationVariable::RangedIntCustomizationVariable(const RangedIntCustomizationVariable& m) : CustomizationVariable(), Param() {
	setType(RANGEDINTCUSTOMIZATIONVARIABLE);

	variableName = m.variableName;
	minValueInclusive = m.minValueInclusive;
	defaultValue = m.defaultValue;
	maxValueExclusive = m.maxValueExclusive;
}

RangedIntCustomizationVariable& RangedIntCustomizationVariable::operator=(const RangedIntCustomizationVariable& m) {
	variableName = m.variableName;
	minValueInclusive = m.minValueInclusive;
	defaultValue = m.defaultValue;
	maxValueExclusive = m.maxValueExclusive;

	return *this;
}

RangedIntCustomizationVariable::~RangedIntCustomizationVariable() {
}

int RangedIntCustomizationVariable::getDefaultValue() const {
	return defaultValue;
}

String RangedIntCustomizationVariable::toString() const {
	StringBuffer stream;
	/*stream << "variableName" << " = " << variableName.toString() << "\n";
	stream << "minValueInclusive" << " = " << minValueInclusive.toString() << "\n";
	stream << "defaultValue" << " = " << defaultValue.toString() << "\n";
	stream << "maxValueExclusive" << " = " << maxValueExclusive.toString() << "\n";*/

	stream << "{";

	stream << variableName.toString() << ", " << minValueInclusive.toString() << ", " << defaultValue.toString() << ", " << maxValueExclusive.toString();

	stream << "}";

	return stream.toString();
}

bool RangedIntCustomizationVariable::parse(Chunk* source) {
	IffStream* iffStream = source->getIffStream();

	Chunk* chunk = iffStream->openChunk('PCNT');

	if (chunk == nullptr) {
		// std::cout << "could not open pcnt\n";
		return false;
	}

	int vars = iffStream->getInt();

	iffStream->closeChunk('PCNT');

	for (int j = 0; j < vars; ++j) {
		Chunk* var = iffStream->openChunk('XXXX');

		String varName;
		var->readString(varName);

		// std::cout << "parsing RICV:[" << varName.toStdString() << "]\n";

		if (varName == "variableName") {
			variableName.parse(var);
		} else if (varName == "minValueInclusive") {
			minValueInclusive.parse(var);
		} else if (varName == "defaultValue") {
			defaultValue.parse(var);
		} else if (varName == "maxValueExclusive") {
			maxValueExclusive.parse(var);
		}

		iffStream->closeChunk('XXXX');
	}

	return true;
}

const String& RangedIntCustomizationVariable::getVariableName() const {
	return variableName.get();
}