/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/staticobject/StaticObject.h"

class StaticObjectMessage3 : public BaseLineMessage {
public:
	StaticObjectMessage3(StaticObject* stao);
	
};
