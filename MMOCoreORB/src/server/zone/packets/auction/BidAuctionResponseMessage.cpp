#include "BidAuctionResponseMessage.h"

BidAuctionResponseMessage::BidAuctionResponseMessage(uint64 objectid, int status) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x8FCBEF4A); // opcode

	insertLong(objectid); // ObjectID player is bidding on.
	insertInt(status);
}