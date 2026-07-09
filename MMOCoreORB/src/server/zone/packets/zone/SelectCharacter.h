/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class SelectCharacter : public BaseMessage {
public:
	SelectCharacter(uint64 characterID);

	static uint64 parse(Packet* pack);
};
