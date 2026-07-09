#include "unkZone.h"

unkZone::unkZone() : BaseMessage() {
	insertShort(0x02);
	insertInt(0x58C07F21);
	insertByte(0x44);
	insertByte(0x05);
	insertByte(0);
	insertByte(0);
}