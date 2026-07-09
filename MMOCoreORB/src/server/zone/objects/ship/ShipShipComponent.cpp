#include "ShipComponent.h"

ShipComponent::ShipComponent() {
}

void ShipComponent::readObject(DataTableRow* row) {
	row->getCell(0)->getValue(name);
	row->getCell(1)->getValue(objectTemplate);
	row->getCell(2)->getValue(sharedObjectTemplate);
	row->getCell(3)->getValue(componentType);
	row->getCell(4)->getValue(compatibility);
}

const String& ShipComponent::getCompatibility() const {
	return compatibility;
}

const String& ShipComponent::getComponentType() const {
	return componentType;
}

const String& ShipComponent::getName() const {
	return name;
}

const String& ShipComponent::getObjectTemplate() const {
	return objectTemplate;
}

const String& ShipComponent::getSharedObjectTemplate() const {
	return sharedObjectTemplate;
}