#include "IntangibleObjectMessage3.h"
#include "server/zone/objects/tangible/TangibleObject.h"

IntangibleObjectMessage3::IntangibleObjectMessage3(IntangibleObject* itno, uint32 objType, uint16 opcnt) : BaseLineMessage(itno->getObjectID(), objType, 3, opcnt) {
	// Complexity
	insertFloat(1);

	insertStringId(itno->getObjectName());

	// Custom Name
	insertUnicode(itno->getCustomObjectName());

	// Volume
	int volume = 0;

	if (itno->isTangibleObject()) {
		volume = itno->asTangibleObject()->getVolume();
	} else {
		volume = itno->getDataSize();
	}

	insertInt(volume);

	// Unused?
	insertInt(itno->getStatus());

	setSize();
}