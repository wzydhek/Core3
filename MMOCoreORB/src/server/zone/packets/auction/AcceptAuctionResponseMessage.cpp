#include "AcceptAuctionResponseMessage.h"

AcceptAuctionResponseMessage::AcceptAuctionResponseMessage(uint64 objectID, uint32 errorCode) {
	insertShort(0x03);
	insertInt(0xC58A446E); // AcceptAuctionResponseMessage

	insertLong(objectID);
	insertInt(errorCode);
}