#pragma once

#include "engine/service/proto/BaseMessage.h"

class GetAuctionDetailsResponse : public BaseMessage {
public:
	GetAuctionDetailsResponse(uint64 objectID, const UnicodeString& description);
};
