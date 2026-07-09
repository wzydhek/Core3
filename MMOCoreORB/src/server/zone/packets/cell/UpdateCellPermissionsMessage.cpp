#include "UpdateCellPermissionsMessage.h"

UpdateCellPermissionsMessage::UpdateCellPermissionsMessage(uint64 coId, bool allowEntry) : BaseMessage() {
	insertShort(0x03);	   // insertShort(0x04);
	insertInt(0xF612499C); // CRC

	insertByte((byte)allowEntry); // 0 denies, 1 allows.
	insertLong(coId);
}