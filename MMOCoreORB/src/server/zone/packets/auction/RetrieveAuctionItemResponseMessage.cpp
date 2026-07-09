#include "RetrieveAuctionItemResponseMessage.h"

RetrieveAuctionItemResponseMessage::RetrieveAuctionItemResponseMessage(uint64 objectid, int status) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x9499EF8C); // opcode

	insertLong(objectid); // ObjectID player retrieved.
	insertInt(status);	  // status 0 - succeed, 12 - inventory full
}