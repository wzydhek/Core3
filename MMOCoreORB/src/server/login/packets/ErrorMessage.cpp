#include "ErrorMessage.h"

ErrorMessage::ErrorMessage(const String& errorType, const String& errorMsg, uint8 fatal) : BaseMessage() {
	insertShort(0x03);
	insertInt(STRING_HASHCODE("ErrorMessage")); // 0xB5ABF91A

	insertAscii(errorType);
	insertAscii(errorMsg);
	insertByte(fatal);
}