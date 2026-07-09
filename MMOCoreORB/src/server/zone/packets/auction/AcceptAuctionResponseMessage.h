/*
 * AcceptAuctionResponseMessage.h
 *
 *  Created on: Apr 29, 2012
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class AcceptAuctionResponseMessage : public BaseMessage {
public:
	AcceptAuctionResponseMessage(uint64 objectID, uint32 errorCode);
};
