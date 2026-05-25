/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"

class GuildObjectMessage6 : public BaseLineMessage {
public:
	GuildObjectMessage6(uint64 oid)
			: BaseLineMessage(oid, 0x47494C44, 6, 0x01) {
		
		insertInt(0x3B);
		
		setSize();
	}
};
