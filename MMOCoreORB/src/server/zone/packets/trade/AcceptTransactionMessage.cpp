#include "AcceptTransactionMessage.h"

AcceptTransactionMessage::AcceptTransactionMessage() : BaseMessage(6) {
	insertShort(1);
	insertInt(0xB131CA17);
}