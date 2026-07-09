#include "SlicingToolTemplate.h"

SlicingToolTemplate::SlicingToolTemplate() {
	effectiveness = 0;
}

SlicingToolTemplate::~SlicingToolTemplate() {
}

void SlicingToolTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	effectiveness = templateData->getFloatField("effectiveness");
}

float SlicingToolTemplate::getEffectiveness() const {
	return effectiveness;
}