#include "ShipDeedTemplate.h"

ShipDeedTemplate::ShipDeedTemplate() {
	shipControlDevice = "";
	shipType = 0;

	setLoggingName("ShipDeedTemplate");
}

ShipDeedTemplate::~ShipDeedTemplate() {
}

void ShipDeedTemplate::readObject(LuaObject* templateData) {
	DeedTemplate::readObject(templateData);

	shipControlDevice = templateData->getStringField("shipControlDevice");
	shipType = templateData->getIntField("shipType");
}

const String& ShipDeedTemplate::getShipControlDeviceTemplate() {
	return shipControlDevice;
}

int ShipDeedTemplate::getShipType() {
	return shipType;
}

bool ShipDeedTemplate::isShipDeedTemplate() {
	return true;
}