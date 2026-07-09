#include "unkByteFlag.h"

unkByteFlag::unkByteFlag() : BaseMessage(7) {
	insertShort(0x02);
	insertInt(0x7102B15F);
	insertByte(1);
}

void unkByteFlag::parse(Packet* pack) {
	uint16 ackSequence = pack->parseShort();
}