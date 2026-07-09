#include "VehicleDeedTemplate.h"

VehicleDeedTemplate::VehicleDeedTemplate() {
}

VehicleDeedTemplate::~VehicleDeedTemplate() {
}

void VehicleDeedTemplate::readObject(LuaObject* templateData) {
	DeedTemplate::readObject(templateData);

	controlDeviceObjectTemplate = templateData->getStringField("controlDeviceObjectTemplate");
}

String VehicleDeedTemplate::getControlDeviceObjectTemplate() {
	return controlDeviceObjectTemplate;
}