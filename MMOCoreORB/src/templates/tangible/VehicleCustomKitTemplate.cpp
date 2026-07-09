#include "VehicleCustomKitTemplate.h"

VehicleCustomKitTemplate::VehicleCustomKitTemplate() {
}

VehicleCustomKitTemplate::~VehicleCustomKitTemplate() {
}

void VehicleCustomKitTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
}

bool VehicleCustomKitTemplate::isVehicleCustomKitTemplate() {
	return true;
}