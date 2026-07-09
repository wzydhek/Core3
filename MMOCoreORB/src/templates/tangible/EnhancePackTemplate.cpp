#include "EnhancePackTemplate.h"

EnhancePackTemplate::EnhancePackTemplate() {
	medicineUse = 0;
	effectiveness = 0;
	absorption = 0;
	duration = 0;
	attribute = 0;
}

EnhancePackTemplate::~EnhancePackTemplate() {
}

void EnhancePackTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	medicineUse = templateData->getIntField("medicineUse");
	effectiveness = templateData->getFloatField("effectiveness");
	absorption = templateData->getFloatField("absorption");
	duration = templateData->getFloatField("duration");
	attribute = templateData->getIntField("attribute");
}

int EnhancePackTemplate::getMedicineUse() {
	return medicineUse;
}

float EnhancePackTemplate::getEffectiveness() {
	return effectiveness;
}

float EnhancePackTemplate::getAbsorption() {
	return absorption;
}

byte EnhancePackTemplate::getAttribute() {
	return attribute;
}

float EnhancePackTemplate::getDuration() {
	return duration;
}

bool EnhancePackTemplate::isEnhancePackTemplate() {
	return true;
}