/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

// Status:
//  0 - Success
//  1 - You are not allowed to cancel that auction
//  2 - You can't cancel that item because it is invalid
//  8 - You must be the owner of an item to cancel the sale
// 15 - That auction has already been completed. It is too late to cancel.

namespace server {
namespace zone {
namespace packets {
namespace auction {

class CancelLiveAuctionResponseMessage : public BaseMessage {
public:
	const static int SUCCESS = 0;
	const static int NOTALLOWED = 1;
	const static int INVALIDITEM = 2;
	const static int NOTOWNER = 8;
	const static int ALREADYCOMPLETED = 15;
public:
	CancelLiveAuctionResponseMessage(uint64 objectid, int status);

};

} // namespace auction
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::auction;
