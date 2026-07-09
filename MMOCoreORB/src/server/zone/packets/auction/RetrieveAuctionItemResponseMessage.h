/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

// Status:
//  0 - Success
//  1 - You are not allowed to retrieve that item
// 12 - Inventory full

class RetrieveAuctionItemResponseMessage : public BaseMessage {
public:
	const static int NOTALLOWED = 1;
	const static int FULLINVENTORY = 12;

	const static int TOOFAR = 0x100;
	const static int DONTRETRIEVE = 0x200;
public:
	RetrieveAuctionItemResponseMessage(uint64 objectid, int status);
	
};
