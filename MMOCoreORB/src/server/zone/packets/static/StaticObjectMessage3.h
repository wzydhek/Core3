/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/staticobject/StaticObject.h"

class StaticObjectMessage3 : public BaseLineMessage {
public:
	StaticObjectMessage3(StaticObject* stao) 
			: BaseLineMessage(stao->getObjectID(), 0x4F415453, 3, 4) {

		insertInt(0);
		insertStringId(stao->getObjectName());
		insertCustomName(stao->getCustomObjectName());
		insertInt(0xFF);

		setSize();
	}
	
};
