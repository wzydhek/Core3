#include "LootSchematicTemplate.h"

LootSchematicTemplate::LootSchematicTemplate() {
	targetDraftSchematic = "";
	targetUseCount = 1;
	requiredSkill = "";
}

LootSchematicTemplate::~LootSchematicTemplate() {
}

void LootSchematicTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	targetDraftSchematic = templateData->getStringField("targetDraftSchematic");
	targetUseCount = templateData->getIntField("targetUseCount");
	requiredSkill = templateData->getStringField("requiredSkill");
}

const String& LootSchematicTemplate::getTargetDraftSchematic() {
	return targetDraftSchematic;
}

const String& LootSchematicTemplate::getRequiredSkill() {
	return requiredSkill;
}

int LootSchematicTemplate::getTargetUseCount() {
	return targetUseCount;
}