#include "StimPackTemplate.h"

StimPackTemplate::StimPackTemplate() {
	medicineUse = 0;
	effectiveness = 0;
	medicineClass = 0;
}

StimPackTemplate::~StimPackTemplate() {
}

void StimPackTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	medicineUse = templateData->getIntField("medicineUse");
	effectiveness = templateData->getFloatField("effectiveness");
	medicineClass = templateData->getIntField("medicineClass");

	LuaObject atts = templateData->getObjectField("attributes");

	for (int i = 0; i < atts.getTableSize(); ++i) {
		byte att = atts.getIntAt(i + 1);

		attributes.add(att);
	}

	atts.pop();
}

int StimPackTemplate::getMedicineUse() {
	return medicineUse;
}

float StimPackTemplate::getEffectiveness() {
	return effectiveness;
}

bool StimPackTemplate::isStimPackTemplate() {
	return true;
}

int StimPackTemplate::getMedicineClass() {
	return medicineClass;
}

Vector<byte> StimPackTemplate::getAttributes() {
	return attributes;
}