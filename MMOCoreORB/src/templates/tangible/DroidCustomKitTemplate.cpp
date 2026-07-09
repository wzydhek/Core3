#include "DroidCustomKitTemplate.h"

DroidCustomKitTemplate::DroidCustomKitTemplate() {
}

DroidCustomKitTemplate::~DroidCustomKitTemplate() {
}

void DroidCustomKitTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
}

bool DroidCustomKitTemplate::isDroidCustomKitTemplate() {
	return true;
}