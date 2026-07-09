#include "SceneObjectDestroyMessage.h"

SceneObjectDestroyMessage::SceneObjectDestroyMessage(SceneObject* scno) : BaseMessage(18) {
	insertShort(0x03);
	insertInt(0x4D45D504);			 // CRC
	insertLong(scno->getObjectID()); // ObjectID
	insertByte(scno->isHyperspacing() ? 0x01 : 0x00);
}

SceneObjectDestroyMessage::SceneObjectDestroyMessage(uint64 oid) : BaseMessage(18) {
	insertShort(0x03);
	insertInt(0x4D45D504); // CRC
	insertLong(oid);	   // ObjectID
	insertByte(0);
}

SceneObjectDestroyMessage::SceneObjectDestroyMessage(uint64 oid, bool hyperspace) : BaseMessage(18) {
	insertShort(0x03);
	insertInt(0x4D45D504); // CRC
	insertLong(oid);	   // ObjectID
	insertByte(hyperspace);
}