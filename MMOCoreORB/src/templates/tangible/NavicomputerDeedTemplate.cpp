#include "NavicomputerDeedTemplate.h"

NavicomputerDeedTemplate::NavicomputerDeedTemplate() {
}

NavicomputerDeedTemplate::~NavicomputerDeedTemplate() {
}

void NavicomputerDeedTemplate::readObject(LuaObject* templateData) {
	DeedTemplate::readObject(templateData);
	controlDeviceObjectTemplate = templateData->getStringField("controlDeviceObjectTemplate");
	datapadObjectTemplate = templateData->getStringField("datapadObjectTemplate");
}

const String& NavicomputerDeedTemplate::getControlDeviceObjectTemplate() const {
	return controlDeviceObjectTemplate;
}

const String& NavicomputerDeedTemplate::getDatapadObjectTemplate() const {
	return datapadObjectTemplate;
}