#include "ChatInstantMessageToClient.h"

ChatInstantMessageToClient::ChatInstantMessageToClient(const String& game, const String& galaxy, const String& name, const UnicodeString& message) : BaseMessage() {
	insertShort(0x05);
	insertInt(0x3C565CED); // CRC

	insertAscii(game);
	insertAscii(galaxy);
	insertAscii(name);
	insertUnicode(message);

	insertInt(0x00);

	setCompression(true);
}