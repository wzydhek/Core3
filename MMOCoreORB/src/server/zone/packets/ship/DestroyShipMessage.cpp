#include "DestroyShipMessage.h"

DestroyShipMessage::DestroyShipMessage(uint64 objectID, float scale) : BaseMessage() {
	insertShort(0x12);
	insertInt(0x5C680884); // CRC
	insertLong(objectID);
	insertFloat(scale);
}