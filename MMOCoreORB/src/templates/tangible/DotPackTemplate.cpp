#include "DotPackTemplate.h"

DotPackTemplate::DotPackTemplate() {
	medicineUse = 0;
	effectiveness = 0;
	duration = 0;
	area = 0;
	range = 0;
	potency = 0;
	rangeMod = 0;
	pool = 0;
	dotType = 0;
	hasArea = false;
}

DotPackTemplate::~DotPackTemplate() {
}

void DotPackTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	medicineUse = templateData->getIntField("medicineUse");
	effectiveness = templateData->getFloatField("effectiveness");
	duration = templateData->getIntField("duration");
	area = templateData->getFloatField("area");
	hasArea = area != 0;
	range = templateData->getFloatField("range");
	rangeMod = templateData->getFloatField("rangeMod");
	pool = templateData->getIntField("pool");
	dotType = templateData->getIntField("dotType");
	potency = templateData->getFloatField("potency");
	commandToExecute = templateData->getStringField("commandToExecute");
}

int DotPackTemplate::getMedicineUse() {
	return medicineUse;
}

float DotPackTemplate::getEffectiveness() {
	return effectiveness;
}

uint32 DotPackTemplate::getPool() {
	return pool;
}

float DotPackTemplate::getRange() {
	return range;
}

float DotPackTemplate::getArea() {
	return area;
}

bool DotPackTemplate::isArea() {
	return hasArea;
}

float DotPackTemplate::getRangeMod() {
	return rangeMod;
}

uint32 DotPackTemplate::getDuration() {
	return duration;
}

float DotPackTemplate::getPotency() {
	return potency;
}

uint32 DotPackTemplate::getDotType() {
	return dotType;
}

String& DotPackTemplate::getCommandToExecute() {
	return commandToExecute;
}

bool DotPackTemplate::isDotPackTemplate() {
	return true;
}