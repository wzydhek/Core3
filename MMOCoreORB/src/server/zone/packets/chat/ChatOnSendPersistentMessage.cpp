#include "ChatOnSendPersistentMessage.h"

ChatOnSendPersistentMessage::ChatOnSendPersistentMessage(uint32 seq, int returnCode) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x94E7A7AE); // CRC

	insertInt(returnCode);

	insertInt(seq);
}