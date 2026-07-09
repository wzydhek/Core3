#include "ShipComponentData.h"

ShipComponentData::ShipComponentData() {
}

void ShipComponentData::readObject(DataTableRow* row) {
	row->getCell(0)->getValue(name);
	row->getCell(1)->getValue(objectTemplate);
	row->getCell(2)->getValue(sharedObjectTemplate);
	row->getCell(3)->getValue(componentType);
	row->getCell(4)->getValue(compatibility);
}

const String& ShipComponentData::getCompatibility() const {
	return compatibility;
}

const String& ShipComponentData::getComponentType() const {
	return componentType;
}

const String& ShipComponentData::getName() const {
	return name;
}

const String& ShipComponentData::getObjectTemplate() const {
	return objectTemplate;
}

const String& ShipComponentData::getSharedObjectTemplate() const {
	return sharedObjectTemplate;
}