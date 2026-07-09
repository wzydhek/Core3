#include "DroidCraftingModuleTemplate.h"

DroidCraftingModuleTemplate::DroidCraftingModuleTemplate() : craftingType(0) {
}

DroidCraftingModuleTemplate::~DroidCraftingModuleTemplate() {
}

void DroidCraftingModuleTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
	craftingType = templateData->getIntField("craftingType");
	craftingStationTemplate = templateData->getStringField("craftingStationTemplate");
	attributeListString = templateData->getStringField("attributeListString");
}

int DroidCraftingModuleTemplate::getCraftingType() {
	return craftingType;
}

String& DroidCraftingModuleTemplate::getCraftingStationTemplate() {
	return craftingStationTemplate;
}

String& DroidCraftingModuleTemplate::getAttributeListString() {
	return attributeListString;
}

bool DroidCraftingModuleTemplate::isDroidCraftingModuleTemplate() {
	return true;
}