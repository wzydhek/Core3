#include "StaticObjectMessage3.h"

StaticObjectMessage3::StaticObjectMessage3(StaticObject* stao) : BaseLineMessage(stao->getObjectID(), 0x4F415453, 3, 4) {
	insertInt(0);
	insertStringId(stao->getObjectName());
	insertCustomName(stao->getCustomObjectName());
	insertInt(0xFF);

	setSize();
}