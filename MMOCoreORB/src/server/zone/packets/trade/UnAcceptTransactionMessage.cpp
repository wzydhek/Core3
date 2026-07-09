#include "UnAcceptTransactionMessage.h"

UnAcceptTransactionMessage::UnAcceptTransactionMessage() : BaseMessage(6) {
	insertShort(1);
	insertInt(0xE81E4382);
}