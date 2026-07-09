#include "PlayMusicMessage.h"

PlayMusicMessage::PlayMusicMessage(const String& soundFile, uint64 target, int unkInt, bool unkBool) : BaseMessage() {
	insertShort(0x05);
	insertInt(0x04270D8A); // CRC
	insertAscii(soundFile);

	//?
	insertLong(target);
	insertInt(unkInt);
	insertByte(unkBool);
}