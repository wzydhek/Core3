/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/intangible/IntangibleObject.h"

class IntangibleObjectDeltaMessage3 : public DeltaMessage {
	IntangibleObject* itno;

public:
	IntangibleObjectDeltaMessage3(IntangibleObject* it) : DeltaMessage(it->getObjectID(), 0x4F4E5449, 3) {
		itno = it;
	}

	void updateName(const UnicodeString& name) {
		addUnicodeUpdate(0x02, name);
	}

	void updateDataSize(float dataSize) {
		addFloatUpdate(0x03, dataSize);
	}

	void updateStatus(uint32 value) {
		addIntUpdate(0x04, value);
	}
};
