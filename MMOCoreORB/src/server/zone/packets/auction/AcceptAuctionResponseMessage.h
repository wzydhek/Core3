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
	AcceptAuctionResponseMessage(uint64 objectID, uint32 errorCode) {
		insertShort(0x03);
		insertInt(0xC58A446E); //AcceptAuctionResponseMessage

		insertLong(objectID);
		insertInt(errorCode);
	}
};
