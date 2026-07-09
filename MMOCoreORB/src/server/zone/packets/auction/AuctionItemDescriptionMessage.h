/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class AuctionItemDescriptionMessage : public BaseMessage {
	
public:
	AuctionItemDescriptionMessage(uint64 objectid, UnicodeString& description);
	
};
