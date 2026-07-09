#include "RangedStimPackTemplate.h"

RangedStimPackTemplate::RangedStimPackTemplate() {
	effectiveness = 0;
	range = 0;
	area = 0;
	rangeMod = 0;
}

RangedStimPackTemplate::~RangedStimPackTemplate() {
}

void RangedStimPackTemplate::readObject(LuaObject* templateData) {
	StimPackTemplate::readObject(templateData);

	range = templateData->getFloatField("range");
	rangeMod = templateData->getFloatField("rangeMod");
	area = templateData->getFloatField("area");
	effectiveness = templateData->getFloatField("effectiveness");
}

float RangedStimPackTemplate::getEffectiveness() {
	return effectiveness;
}

float RangedStimPackTemplate::getRange() {
	return range;
}

float RangedStimPackTemplate::getArea() {
	return area;
}

float RangedStimPackTemplate::getRangeMod() {
	return rangeMod;
}

bool RangedStimPackTemplate::isRangedStimPackTemplate() {
	return true;
}