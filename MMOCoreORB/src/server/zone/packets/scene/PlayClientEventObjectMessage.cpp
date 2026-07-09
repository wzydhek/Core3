#include "PlayClientEventObjectMessage.h"

PlayClientEventObjectMessage::PlayClientEventObjectMessage(SceneObject* obj, const String& file, const String& aux) : BaseMessage() {
	insertShort(0x05);
	insertInt(0xAF83C3F2); // CRC
	insertAscii(file.toCharArray());
	insertAscii(aux.toCharArray());
	insertLong(obj->getObjectID());
}