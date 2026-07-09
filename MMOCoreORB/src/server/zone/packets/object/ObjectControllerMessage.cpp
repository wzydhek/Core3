#include "ObjectControllerMessage.h"

ObjectControllerMessage::ObjectControllerMessage(uint64 objid, uint32 header1, uint32 header2, bool comp) {
	insertShort(0x05);
	insertInt(0x80CE5E46); // CRC
	insertInt(header1);
	insertInt(header2);
	insertLong(objid);
	insertInt(0x00);

	setCompression(comp);
}