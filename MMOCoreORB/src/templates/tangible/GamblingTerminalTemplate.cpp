#include "GamblingTerminalTemplate.h"

GamblingTerminalTemplate::GamblingTerminalTemplate() : machineType(0) {
}

GamblingTerminalTemplate::~GamblingTerminalTemplate() {
}

void GamblingTerminalTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	machineType = templateData->getIntField("machineType");
}

int GamblingTerminalTemplate::getMachineType() const {
	return machineType;
}

void GamblingTerminalTemplate::setMachineType(int machineType) {
	this->machineType = machineType;
}

bool GamblingTerminalTemplate::isGamblingTerminalTemplate() {
	return true;
}