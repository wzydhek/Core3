#include "ChatSystemMessage.h"

ChatSystemMessage::ChatSystemMessage(const UnicodeString& message, byte displayType) : BaseMessage() {
	insertShort(0x04);
	insertInt(0x6D2A6413); // ChatSystemMessage

	insertByte(displayType);

	insertUnicode(message);
	insertInt(0); // No params

	setCompression(true);
}

ChatSystemMessage::ChatSystemMessage(StringIdChatParameter& sid, byte displayType) : BaseMessage() {
	insertShort(0x04);
	insertInt(0x6D2A6413);

	insertByte(displayType);
	insertInt(0);

	int offset = getOffset();

	insertInt(0);

	sid.insertToMessage(this);

	int size = (getOffset() - offset - 4) / 2;

	insertInt(offset, size);

	setCompression(true);
}