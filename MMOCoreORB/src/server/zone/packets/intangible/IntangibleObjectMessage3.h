/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/intangible/IntangibleObject.h"

class IntangibleObjectMessage3 : public BaseLineMessage {
public:
	IntangibleObjectMessage3(IntangibleObject* itno, uint32 objType = 0x4F4E5449, uint16 opcnt = 5);

};
