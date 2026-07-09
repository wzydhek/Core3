#include "VehicleObjectTemplate.h"

VehicleObjectTemplate::VehicleObjectTemplate() {
	decayRate = 0;
	decayCycle = 0;
}

VehicleObjectTemplate::~VehicleObjectTemplate() {
}

void VehicleObjectTemplate::readObject(LuaObject* templateData) {
	SharedCreatureObjectTemplate::readObject(templateData);
	decayRate = templateData->getIntField("decayRate");
	decayCycle = templateData->getIntField("decayCycle");
}

bool VehicleObjectTemplate::isVehicleObjectTemplate() {
	return true;
}

int VehicleObjectTemplate::getDecayRate() {
	return decayRate;
}

int VehicleObjectTemplate::getDecayCycle() {
	return decayCycle;
}