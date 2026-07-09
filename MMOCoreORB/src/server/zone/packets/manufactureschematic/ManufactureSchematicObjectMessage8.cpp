#include "ManufactureSchematicObjectMessage8.h"

ManufactureSchematicObjectMessage8::ManufactureSchematicObjectMessage8(uint64 oid) : BaseLineMessage(oid, 0x4D53434F, 8, 0x00) {
	setSize();
}