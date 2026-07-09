#include "BeginTradeMessage.h"

BeginTradeMessage::BeginTradeMessage(uint64 playerID) : BaseMessage(0x0E) {
	insertShort(0x02);
	insertInt(0x325932D8);
	insertLong(playerID);
}