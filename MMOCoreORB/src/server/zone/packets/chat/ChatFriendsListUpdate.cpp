#include "ChatFriendsListUpdate.h"

ChatFriendsListUpdate::ChatFriendsListUpdate(const String& name, const String& server, bool online) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x6CD2FCD8); // CRC

	insertAscii("SWG");
	insertAscii(server);
	insertAscii(name);

	insertByte(online);
}