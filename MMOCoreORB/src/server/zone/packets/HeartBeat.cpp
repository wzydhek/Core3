#include "HeartBeat.h"

HeartBeat::HeartBeat() : BaseMessage() {
	insertShort(0x01);
	insertInt(0xA16CF9AF); // opcode: HeartBeat
}