/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"

class Emote : public ObjectControllerMessage {
public:
	Emote(uint64 senderID, uint64 targetID, uint64 emoteTargetID, uint32 emoteID, bool doAnim = true, bool doText = true);

};
