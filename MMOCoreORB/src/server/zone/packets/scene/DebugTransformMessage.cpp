#include "DebugTransformMessage.h"

DebugTransformMessage::DebugTransformMessage() : BaseMessage() {
	insertShort(0x09);
	insertInt(0xD0CDAA62); // CRC

	insertInt(0);
	insertInt(0);
	insertInt(0);
	insertInt(0);
	insertInt(0);
	insertInt(0);
	insertInt(0);
	insertLong(0);
}