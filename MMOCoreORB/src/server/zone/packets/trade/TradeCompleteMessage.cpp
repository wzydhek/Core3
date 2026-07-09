#include "TradeCompleteMessage.h"

TradeCompleteMessage::TradeCompleteMessage() : BaseMessage(0x06) {
	insertShort(0x01);
	insertInt(0xC542038B);
}