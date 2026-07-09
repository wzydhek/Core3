#include "LinkDeadMessage.h"

LinkDeadMessage::LinkDeadMessage() : BaseMessage() {
	insertShort(0x05);
	insertInt(0xA16CF9AF); // opcode
}