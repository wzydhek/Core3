#include "ContainerTemplate.h"

ContainerTemplate::ContainerTemplate() : lock(false) {
}

ContainerTemplate::~ContainerTemplate() {
}

void ContainerTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	lock = templateData->getByteField("locked");
}

bool ContainerTemplate::getLocked() const {
	return lock;
}