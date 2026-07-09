#include "ChatServerStatus.h"

ChatServerStatus::ChatServerStatus(byte flag) : BaseMessage() {
	insertShort(0x02);
	insertInt(0x7102B15F); // CRC

	insertByte(flag); // status. -0 offline  1 online
}