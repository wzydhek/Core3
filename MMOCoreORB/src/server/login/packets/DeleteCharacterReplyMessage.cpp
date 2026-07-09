#include "DeleteCharacterReplyMessage.h"

DeleteCharacterReplyMessage::DeleteCharacterReplyMessage(int Failure) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x8268989B); // DeleteCharacterReplyMessage
	insertInt(Failure);
}