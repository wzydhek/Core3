/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/intangible/IntangibleObject.h"

class IntangibleObjectDeltaMessage3 : public DeltaMessage {
	IntangibleObject* itno;

public:
	IntangibleObjectDeltaMessage3(IntangibleObject* it);

	void updateName(const UnicodeString& name);

	void updateDataSize(float dataSize);

	void updateStatus(uint32 value);
};
