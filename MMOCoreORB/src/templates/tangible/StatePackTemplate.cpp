#include "StatePackTemplate.h"

StatePackTemplate::StatePackTemplate() {
	medicineUse = 0;
	state = 0;
}

StatePackTemplate::~StatePackTemplate() {
}

void StatePackTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	medicineUse = templateData->getIntField("medicineUse");
	state = templateData->getLongField("state");
}

int StatePackTemplate::getMedicineUse() {
	return medicineUse;
}

uint64 StatePackTemplate::getState() {
	return state;
}

bool StatePackTemplate::isStatePackTemplate() {
	return true;
}