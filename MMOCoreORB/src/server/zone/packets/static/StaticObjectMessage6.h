/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/staticobject/StaticObject.h"

class StaticObjectMessage6 : public BaseLineMessage {
public:
	StaticObjectMessage6(StaticObject* stao);
	
};
