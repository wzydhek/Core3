#include "IntangibleObjectDeltaMessage3.h"

IntangibleObjectDeltaMessage3::IntangibleObjectDeltaMessage3(IntangibleObject* it) : DeltaMessage(it->getObjectID(), 0x4F4E5449, 3) {
	itno = it;
}

void IntangibleObjectDeltaMessage3::updateName(const UnicodeString& name) {
	addUnicodeUpdate(0x02, name);
}

void IntangibleObjectDeltaMessage3::updateDataSize(float dataSize) {
	addFloatUpdate(0x03, dataSize);
}

void IntangibleObjectDeltaMessage3::updateStatus(uint32 value) {
	addIntUpdate(0x04, value);
}