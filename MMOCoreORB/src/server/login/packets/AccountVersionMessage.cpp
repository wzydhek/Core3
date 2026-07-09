#include "AccountVersionMessage.h"

AccountVersionMessage::AccountVersionMessage(const String& username, const String& password, const String& version) : BaseMessage() {
	insertShort(0x04);
	insertInt(0x41131F96);

	insertAscii(username);
	insertAscii(password);
	insertAscii(version);
	insertInt(STRING_HASHCODE("SWGEmu")); // required for SWGEmu login server
}

void AccountVersionMessage::parse(Packet* pack, String& username, String& password, String& version) {
	pack->parseAscii(username);
	pack->parseAscii(password);

	pack->parseAscii(version);
}