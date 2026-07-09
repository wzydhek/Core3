#include "StructureDeedTemplate.h"

StructureDeedTemplate::StructureDeedTemplate() {
}

void StructureDeedTemplate::readObject(LuaObject* obj) {
	DeedTemplate::readObject(obj);

	placementComponent = obj->getStringField("placeStructureComponent");
}

const String& StructureDeedTemplate::getStructurePlacementComponent() {
	return placementComponent;
}