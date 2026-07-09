#include "CurePackTemplate.h"

CurePackTemplate::CurePackTemplate() {
	effectiveness = 0;
	state = 0;
	area = 0;
	medicineUse = 0;
}

CurePackTemplate::~CurePackTemplate() {
}

void CurePackTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	medicineUse = templateData->getIntField("medicineUse");
	state = templateData->getLongField("state");
	commandToExecute = templateData->getStringField("commandToExecute");
	area = templateData->getFloatField("area");
	effectiveness = templateData->getFloatField("effectiveness");
}

float CurePackTemplate::getEffectiveness() {
	return effectiveness;
}

uint64 CurePackTemplate::getState() {
	return state;
}

float CurePackTemplate::getArea() {
	return area;
}

int CurePackTemplate::getMedicineUse() {
	return medicineUse;
}

String& CurePackTemplate::getCommandToExecute() {
	return commandToExecute;
}

bool CurePackTemplate::isCurePackTemplate() {
	return true;
}