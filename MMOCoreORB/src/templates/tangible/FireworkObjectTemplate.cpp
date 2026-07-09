#include "FireworkObjectTemplate.h"

FireworkObjectTemplate::FireworkObjectTemplate() {
	isShow = false;
}

FireworkObjectTemplate::~FireworkObjectTemplate() {
}

void FireworkObjectTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	fireworkObject = templateData->getStringField("fireworkObject");
	isShow = templateData->getBooleanField("showPackage");
}

String FireworkObjectTemplate::getFireworkObject() const {
	return fireworkObject;
}

bool FireworkObjectTemplate::isFireworkShow() {
	return isShow;
}

bool FireworkObjectTemplate::isFireworkObjectTemplate() {
	return true;
}