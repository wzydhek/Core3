/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class SelectCharacter : public BaseMessage {
public:
	SelectCharacter(uint64 characterID) {
		insertShort(0x02);
		insertInt(STRING_HASHCODE("SelectCharacter"));

		insertLong(characterID);
		insertInt(STRING_HASHCODE("SWGEmu")); // required for SWGEmu servers
	}

	static uint64 parse(Packet* pack) {
		return pack->parseInt(10);
	}
};
