/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class unkByteFlag : public BaseMessage {
public:
	unkByteFlag() : BaseMessage(7) {
		insertShort(0x02);
		insertInt(0x7102B15F);
		insertByte(1);

	}

	static void parse(Packet* pack) {
		uint16 ackSequence = pack->parseShort();
	}
	
};
