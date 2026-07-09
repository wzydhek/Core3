#include "EnterStructurePlacementModeMessage.h"

EnterStructurePlacementModeMessage::EnterStructurePlacementModeMessage(uint64 deedid, String crcpath) : BaseMessage() {
	insertShort(0x03);
	insertInt(0xE8A54DC1); // CRC

	insertLong(deedid);	  // Deed ID
	insertAscii(crcpath); // path to the object.
}