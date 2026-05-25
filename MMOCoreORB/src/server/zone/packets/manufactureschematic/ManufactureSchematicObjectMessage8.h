/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "server/zone/packets/BaseLineMessage.h"

class ManufactureSchematicObjectMessage8 : public BaseLineMessage {
public:
	ManufactureSchematicObjectMessage8(uint64 oid) 
			: BaseLineMessage(oid, 0x4D53434F, 8, 0x00) {

		setSize();
	}
};
