#include "ChatOnSendRoomMessage.h"

ChatOnSendRoomMessage::ChatOnSendRoomMessage(uint32 seq, int error) : BaseMessage() {
	insertShort(0x03);
	insertInt(0xE7B61633); // Opcode
	insertInt(error);
	insertInt(seq);
}