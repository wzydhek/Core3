#include "DroidDeedTemplate.h"

DroidDeedTemplate::DroidDeedTemplate() : species(0) {
}

DroidDeedTemplate::~DroidDeedTemplate() {
}

void DroidDeedTemplate::readObject(LuaObject* templateData) {
	DeedTemplate::readObject(templateData);
	controlDeviceObjectTemplate = templateData->getStringField("controlDeviceObjectTemplate");
	mobileTemplate = templateData->getStringField("mobileTemplate");
	species = templateData->getIntField("species");
}

const String& DroidDeedTemplate::getControlDeviceObjectTemplate() const {
	return controlDeviceObjectTemplate;
}

const String& DroidDeedTemplate::getMobileTemplate() const {
	return mobileTemplate;
}

int DroidDeedTemplate::getSpecies() const {
	return species;
}