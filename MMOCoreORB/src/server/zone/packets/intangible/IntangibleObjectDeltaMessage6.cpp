#include "IntangibleObjectDeltaMessage6.h"

IntangibleObjectDeltaMessage6::IntangibleObjectDeltaMessage6(IntangibleObject* it) : DeltaMessage(it->getObjectID(), 0x4F4E5449, 6) {
	itno = it;
}

void IntangibleObjectDeltaMessage6::updateItemIdentifier(const String& itemName) {
	// addAsciiUpdate(0x00, itemName); Unknown
}