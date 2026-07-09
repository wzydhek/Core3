#include "DogfightTauntPlayerMessage.h"

DogfightTauntPlayerMessage::DogfightTauntPlayerMessage() : BaseMessage() {
	insertShort(0x09);
	insertInt(0xCA2A548B); // CRC

	insertLong(0);
	insertInt(0);
}