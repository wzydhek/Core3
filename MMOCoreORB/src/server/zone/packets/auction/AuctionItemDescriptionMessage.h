/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace auction {

class AuctionItemDescriptionMessage : public BaseMessage {
	
public:
	AuctionItemDescriptionMessage(uint64 objectid, UnicodeString& description);
	
};

} // namespace auction
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::auction;
