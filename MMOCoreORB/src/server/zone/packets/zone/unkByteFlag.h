/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class unkByteFlag : public BaseMessage {
public:
	unkByteFlag();

	static void parse(Packet* pack);
	
};
