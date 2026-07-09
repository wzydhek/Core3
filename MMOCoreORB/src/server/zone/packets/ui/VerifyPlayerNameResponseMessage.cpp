#include "VerifyPlayerNameResponseMessage.h"

VerifyPlayerNameResponseMessage::VerifyPlayerNameResponseMessage(bool success) : BaseMessage() {
	insertShort(0x09);
	insertInt(0xF4C498FD);	   // VerifyPlayerNameResponseMessage
	insertByte((byte)success); // Success or fail
	insertInt(1);
}