#include "ClientOpenContainerMessage.h"

ClientOpenContainerMessage::ClientOpenContainerMessage(SceneObject* container, bool cloose) : BaseMessage() {
	insertShort(0x04);
	insertInt(0xDCA57409);

	insertLong(container->getObjectID());
	insertInt(0);
	insertShort(2);
}

ClientOpenContainerMessage::ClientOpenContainerMessage(SceneObject* container) : BaseMessage() {
	insertShort(0x04);
	insertInt(0xDCA57409);

	insertLong(container->getObjectID());
	insertInt(0);
	insertShort(0);
}

ClientOpenContainerMessage::ClientOpenContainerMessage(uint64 oid, const String& ascii, int test) : BaseMessage() {
	insertShort(0x04);
	insertInt(0xDCA57409);

	insertLong(oid);
	insertAscii(ascii);
}