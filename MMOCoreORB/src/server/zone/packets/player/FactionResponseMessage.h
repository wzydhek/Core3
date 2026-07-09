/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/player/variables/FactionStandingList.h"

class FactionResponseMessage : public BaseMessage {
public:

	FactionResponseMessage(FactionStandingList* fpl);
};
