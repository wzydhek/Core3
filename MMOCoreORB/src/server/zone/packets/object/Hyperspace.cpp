#include "Hyperspace.h"

HyperspaceMessage::HyperspaceMessage(uint64 shpid, int operand) : BaseMessage() {
	insertShort(operand);
	insertInt(0xCBF88482); // Opcode
	insertLong(shpid);
}