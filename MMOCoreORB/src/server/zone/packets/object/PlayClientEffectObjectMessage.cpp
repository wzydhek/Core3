#include "PlayClientEffectObjectMessage.h"

PlayClientEffectObjectMessage::PlayClientEffectObjectMessage(SceneObject* obj, const String& file, const String& aux) : BaseMessage() {
	insertShort(0x05);
	insertInt(0x8855434A); // CRC
	insertAscii(file.toCharArray());
	insertAscii(aux.toCharArray());
	insertLong(obj->getObjectID());
}