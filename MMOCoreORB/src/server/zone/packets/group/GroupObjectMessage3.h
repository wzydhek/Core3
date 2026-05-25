/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/group/GroupObject.h"

class GroupObjectMessage3 : public BaseLineMessage, public Logger {
public:
	GroupObjectMessage3(GroupObject* grup) : BaseLineMessage(grup->getObjectID(), 'GRUP', 0x03, 0x05) {
		//info(true) << "GroupObjectMessage3 called";
		insertFloat(1);

		insertAscii("string_id_table");

		insertInt(0x0);
		insertShort(0x0);
		insertInt(0x0);
		insertInt(0x0);

		insertFloat(1);

		setSize();
	}
};
