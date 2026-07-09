#include "GiveMoneyMessage.h"

GiveMoneyMessage::GiveMoneyMessage(uint32 money) : BaseMessage(10) {
	insertShort(2);
	insertInt(0xD1527EE8);
	insertInt(money);
}