#include "ClientCreateCharacterSuccess.h"

ClientCreateCharacterSuccess::ClientCreateCharacterSuccess(uint64 objid) : BaseMessage() {
	insertShort(0x02);
	insertInt(0x1DB575CC); // opcode: ClientCreateCharacterSuccess
	insertLong(objid);
}