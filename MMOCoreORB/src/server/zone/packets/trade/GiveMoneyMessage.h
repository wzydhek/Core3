/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class GiveMoneyMessage : public BaseMessage {
public:
	GiveMoneyMessage(uint32 money);
};
