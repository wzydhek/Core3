#include "SelectCharacter.h"

SelectCharacter::SelectCharacter(uint64 characterID) {
	insertShort(0x02);
	insertInt(STRING_HASHCODE("SelectCharacter"));

	insertLong(characterID);
	insertInt(STRING_HASHCODE("SWGEmu")); // required for SWGEmu servers
}

uint64 SelectCharacter::parse(Packet* pack) {
	return pack->parseInt(10);
}