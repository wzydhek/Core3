#include "DroidComponentTemplate.h"

DroidComponentTemplate::DroidComponentTemplate() {
}

DroidComponentTemplate::~DroidComponentTemplate() {
}

void DroidComponentTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
}

bool DroidComponentTemplate::isDroidComponentTemplate() {
	return true;
}