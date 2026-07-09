#include "IsFlattenedTheaterMessage.h"

IsFlattenedTheaterMessage::IsFlattenedTheaterMessage(uint64 objectID, bool shouldFlatten) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x4EB0B06A); // CRC

	insertLong(objectID);	   // Object id of the theater
	insertByte(shouldFlatten); // Whether or not to flatten terrain
}