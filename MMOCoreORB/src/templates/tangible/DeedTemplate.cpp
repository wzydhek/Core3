#include "DeedTemplate.h"

DeedTemplate::DeedTemplate() {
}

DeedTemplate::~DeedTemplate() {
}

void DeedTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	generatedObjectTemplate = templateData->getStringField("generatedObjectTemplate");
}

const String& DeedTemplate::getGeneratedObjectTemplate() const {
	return generatedObjectTemplate;
}