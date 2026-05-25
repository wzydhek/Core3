/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/staticobject/StaticObject.h"

class StaticObjectMessage6 : public BaseLineMessage {
public:
	StaticObjectMessage6(StaticObject* stao) 
			: BaseLineMessage(stao->getObjectID(), 0x4F415453, 6, 2) {

		insertInt(0x44);
		insertAscii("String_id_table");
		insertInt(0);
		insertShort(0);

		setSize();
	}
	
};
