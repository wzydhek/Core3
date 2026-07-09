#include "PetDeedTemplate.h"

PetDeedTemplate::PetDeedTemplate() {
}

PetDeedTemplate::~PetDeedTemplate() {
}

void PetDeedTemplate::readObject(LuaObject* templateData) {
	DeedTemplate::readObject(templateData);
	controlDeviceObjectTemplate = templateData->getStringField("controlDeviceObjectTemplate");
	mobileTemplate = templateData->getStringField("mobileTemplate");
}

String PetDeedTemplate::getControlDeviceObjectTemplate() {
	return controlDeviceObjectTemplate;
}

String PetDeedTemplate::getMobileTemplate() {
	return mobileTemplate;
}