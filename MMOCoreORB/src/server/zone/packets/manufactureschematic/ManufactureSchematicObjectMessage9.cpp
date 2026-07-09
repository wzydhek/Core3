#include "ManufactureSchematicObjectMessage9.h"

ManufactureSchematicObjectMessage9::ManufactureSchematicObjectMessage9(uint64 oid) : BaseLineMessage(oid, 0x4D53434F, 9, 0x00) {
	setSize();
}