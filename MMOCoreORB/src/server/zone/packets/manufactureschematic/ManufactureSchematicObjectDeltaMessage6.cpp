#include "ManufactureSchematicObjectDeltaMessage6.h"

ManufactureSchematicObjectDeltaMessage6::ManufactureSchematicObjectDeltaMessage6(SceneObject* schematic) : DeltaMessage(schematic->getObjectID(), 0x4D53434F, 6) {
}

void ManufactureSchematicObjectDeltaMessage6::insertToResourceSlot(int slotNumber) {
	addByteUpdate(5, slotNumber);
}