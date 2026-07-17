/*
 * AcceptAuctionResponseMessage.h
 *
 *  Created on: Apr 29, 2012
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace auction {

class AcceptAuctionResponseMessage : public BaseMessage {
public:
	AcceptAuctionResponseMessage(uint64 objectID, uint32 errorCode);
};

} // namespace auction
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::auction;
