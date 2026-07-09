#include "ManufactureSchematicObjectDeltaMessage3.h"

ManufactureSchematicObjectDeltaMessage3::ManufactureSchematicObjectDeltaMessage3(SceneObject* schematic) : DeltaMessage(schematic->getObjectID(), 0x4D53434F, 3) {
}

void ManufactureSchematicObjectDeltaMessage3::updateComplexity(float complexity) {
	addFloatUpdate(0, complexity);
}

void ManufactureSchematicObjectDeltaMessage3::updateName(String name) {
	addUnicodeUpdate(2, name);
}

void ManufactureSchematicObjectDeltaMessage3::updateCondition(int condition) {
	addIntUpdate(4, condition);
}

void ManufactureSchematicObjectDeltaMessage3::updateManufactureLimit(int limit) {
	addIntUpdate(5, limit);
}

void ManufactureSchematicObjectDeltaMessage3::updateCraftingValues(ManufactureSchematic* manufactureSchematic) {
	CraftingValues* craftingValues = manufactureSchematic->getCraftingValues();

	String name;
	float value;

	int count = craftingValues->getValuesToSendSize();

	startUpdate(5);

	startList(count, count);

	for (int i = 0; i < count; ++i) {
		insertByte(0);
		insertAscii("crafting");
		insertInt(0);
		name = craftingValues->getValuesToSend(i);
		value = craftingValues->getCurrentValue(name);
		insertAscii(name);
		insertFloat(value);
	}
}