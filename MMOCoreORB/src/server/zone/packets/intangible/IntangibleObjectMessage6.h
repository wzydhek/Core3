/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/intangible/IntangibleObject.h"

class IntangibleObjectMessage6 : public BaseLineMessage {
public:
	IntangibleObjectMessage6(IntangibleObject* itno);
};
