#include "CancelLiveAuctionResponseMessage.h"

CancelLiveAuctionResponseMessage::CancelLiveAuctionResponseMessage(uint64 objectid, int status) : BaseMessage() {
	insertShort(0x04);
	insertInt(0x7DA2246C); // opcode

	insertLong(objectid); // ObjectID player canceling.
	insertInt(status);
	insertByte(0); // Unknown
}