#include "WoundPackTemplate.h"

WoundPackTemplate::WoundPackTemplate() {
	medicineUse = 0;
	effectiveness = 0;
	attribute = 0;
}

WoundPackTemplate::~WoundPackTemplate() {
}

void WoundPackTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	medicineUse = templateData->getIntField("medicineUse");
	effectiveness = templateData->getFloatField("effectiveness");
	attribute = templateData->getIntField("attribute");
}

int WoundPackTemplate::getMedicineUse() {
	return medicineUse;
}

float WoundPackTemplate::getEffectiveness() {
	return effectiveness;
}

byte WoundPackTemplate::getAttribute() {
	return attribute;
}

bool WoundPackTemplate::isWoundPackTemplate() {
	return true;
}