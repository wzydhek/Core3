#include "ChatOnGetFriendsList.h"

ChatOnGetFriendsList::ChatOnGetFriendsList(PlayerObject* ghost) : BaseMessage() {
	insertShort(0x03);
	insertInt(0xE97AB594); // CRC

	insertLong(ghost->getParentID());

	setCompression(true);

	String serverName = ghost->getZoneServer()->getGalaxyName();

	const DeltaVector<String>* friendList = ghost->getFriendList();
	insertInt(friendList->size());

	for (int i = 0; i < friendList->size(); ++i) {
		insertAscii("SWG");
		insertAscii(serverName);
		insertAscii(friendList->get(i));
	}
}