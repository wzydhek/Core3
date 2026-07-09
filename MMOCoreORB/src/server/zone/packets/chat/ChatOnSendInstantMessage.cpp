#include "ChatOnSendInstantMessage.h"

ChatOnSendInstantMessage::ChatOnSendInstantMessage(uint32 seq, int result) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x88DBB381); // CRC

	insertInt(result);

	insertInt(seq);
}