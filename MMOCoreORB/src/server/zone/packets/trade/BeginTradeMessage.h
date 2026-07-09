/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class BeginTradeMessage : public BaseMessage {
public:
	BeginTradeMessage(uint64 playerID);
};
