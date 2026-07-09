/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.
*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/intangible/IntangibleObject.h"

class IntangibleObjectDeltaMessage6 : public DeltaMessage {
	IntangibleObject* itno;

public:
	IntangibleObjectDeltaMessage6(IntangibleObject* it);

	void updateItemIdentifier(const String& itemName);
};
