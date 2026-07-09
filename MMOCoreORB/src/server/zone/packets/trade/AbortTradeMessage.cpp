#include "AbortTradeMessage.h"

AbortTradeMessage::AbortTradeMessage() : BaseMessage(6) {
	insertShort(1);
	insertInt(0x9CA80F98);
}