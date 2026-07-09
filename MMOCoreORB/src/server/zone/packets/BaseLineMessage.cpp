#include "BaseLineMessage.h"

BaseLineMessage::BaseLineMessage(const SceneObject* obj, uint32 name, uint8 type, uint16 opcnt) {
	insertShort(0x05);
	insertInt(0x68A75F0C);
	insertLong(const_cast<SceneObject*>(obj)->getObjectID());
	insertInt(name);
	insertByte(type);
	insertInt(0);

	insertShort(opcnt);

	setCompression(true);
}

BaseLineMessage::BaseLineMessage(uint64 oid, uint32 name, uint8 type, uint16 opcnt) {
	insertShort(0x05);
	insertInt(0x68A75F0C);
	insertLong(oid);  // Object ID
	insertInt(name);  // Packet Name
	insertByte(type); // Packet Number
	insertInt(0);	  // Message Size - modified by setSize()

	insertShort(opcnt);

	setCompression(true);
}

void BaseLineMessage::setSize() {
	insertInt(23, size() - 27);
}

void BaseLineMessage::insertStringId(const StringId* id) {
	insertAscii(id->getFile());
	insertInt(0);
	insertAscii(id->getStringID());
}

void BaseLineMessage::insertCustomName(const UnicodeString& name) {
	insertUnicode(name);
}