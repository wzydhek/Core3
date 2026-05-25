/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class FactoryCrateObjectMessage6 : public BaseLineMessage {
public:
	FactoryCrateObjectMessage6(TangibleObject* tano) 
			: BaseLineMessage(tano->getObjectID(), 0x46435954, 6, 0x06) {
		
		insertShort(3);

		insertInt(0);
		insertInt(0);

		insertInt(0);
		insertInt(0);

		insertInt(0);
		insertInt(0);

		insertInt(0);
		insertInt(0);

		insertByte(0);

		setSize();
	}
	
};
