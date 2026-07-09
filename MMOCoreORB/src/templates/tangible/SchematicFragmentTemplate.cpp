#include "SchematicFragmentTemplate.h"

SchematicFragmentTemplate::SchematicFragmentTemplate() {
	totalFragments = 0;
	fragmentBitmask = 0;
	targetSchematic = 0;
}

SchematicFragmentTemplate::~SchematicFragmentTemplate() {
}

void SchematicFragmentTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	totalFragments = templateData->getIntField("totalFragments");
	fragmentBitmask = templateData->getIntField("fragmentBitmask");
	targetSchematic = templateData->getStringField("targetSchematic").hashCode();
}

int SchematicFragmentTemplate::getTotalFragments() {
	return totalFragments;
}

unsigned int SchematicFragmentTemplate::getfragmentBitmask() {
	return fragmentBitmask;
}

bool SchematicFragmentTemplate::isSchematicFragmentTemplate() {
	return true;
}

uint32 SchematicFragmentTemplate::getTargetSchematic() {
	return targetSchematic;
}