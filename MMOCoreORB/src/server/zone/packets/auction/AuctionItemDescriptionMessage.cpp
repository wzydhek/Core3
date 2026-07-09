#include "AuctionItemDescriptionMessage.h"

AuctionItemDescriptionMessage::AuctionItemDescriptionMessage(uint64 objectid, UnicodeString& description) {
	insertShort(2);
	insertInt(0xFE0E644B);

	insertLong(objectid);

	setCompression(true);

	insertUnicode(description);
	insertInt(0);
	insertInt(0);
}