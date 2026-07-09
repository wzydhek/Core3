#include "ChatOnGetIgnoreList.h"

ChatOnGetIgnoreList::ChatOnGetIgnoreList(PlayerObject* ghost) : BaseMessage() {
	insertShort(0x03);
	insertInt(0xF8C275B0); // CRC

	insertLong(ghost->getParentID());

	const DeltaVector<String>* ignoreList = ghost->getIgnoreList();
	insertInt(ignoreList->size());

	for (int i = 0; i < ignoreList->size(); ++i) {
		insertAscii("SWG");
		insertAscii(ghost->getZoneServer()->getGalaxyName());
		insertAscii(ignoreList->get(i));
	}

	setCompression(true);
}