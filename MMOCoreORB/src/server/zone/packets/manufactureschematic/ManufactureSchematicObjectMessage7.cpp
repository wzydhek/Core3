#include "ManufactureSchematicObjectMessage7.h"

ManufactureSchematicObjectMessage7::ManufactureSchematicObjectMessage7(SceneObject* schematic) : BaseLineMessage(schematic->getObjectID(), 0x4D53434F, 7, 0x15) {
}