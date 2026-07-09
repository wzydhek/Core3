#include "InstrumentObjectTemplate.h"

InstrumentObjectTemplate::InstrumentObjectTemplate() {
	instrumentType = 0;
}

void InstrumentObjectTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	instrumentType = templateData->getIntField("instrumentType");
}

int InstrumentObjectTemplate::getInstrumentType() const {
	return instrumentType;
}

bool InstrumentObjectTemplate::isInstrumentObjectTemplate() const {
	return true;
}