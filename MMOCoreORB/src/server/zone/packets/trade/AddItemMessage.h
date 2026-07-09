/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class AddItemMessage : public BaseMessage {
public:
	AddItemMessage(uint64 itemID);
};
