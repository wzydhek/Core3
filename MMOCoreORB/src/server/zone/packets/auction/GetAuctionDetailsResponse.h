#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace auction {

class GetAuctionDetailsResponse : public BaseMessage {
public:
	GetAuctionDetailsResponse(uint64 objectID, const UnicodeString& description);
};

} // namespace auction
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::auction;
