#include "RecycleToolTemplate.h"

RecycleToolTemplate::RecycleToolTemplate() : toolType(0) {
}

RecycleToolTemplate::~RecycleToolTemplate() {
}

void RecycleToolTemplate::readObject(LuaObject* templateData) {
	ContainerTemplate::readObject(templateData);

	toolType = templateData->getByteField("toolType");

	LuaObject resources = templateData->getObjectField("resourceTypes");
	for (int i = 1; i <= resources.getTableSize(); ++i) {
		resourceTypes.add(resources.getStringAt(i));
	}
	resources.pop();
}

short RecycleToolTemplate::getToolType() const {
	return toolType;
}

const Vector<String>& RecycleToolTemplate::getResourceTypes() const {
	return resourceTypes;
}

bool RecycleToolTemplate::isRecycleToolTemplate() const {
	return true;
}