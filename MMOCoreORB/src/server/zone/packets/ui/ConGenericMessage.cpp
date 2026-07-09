#include "ConGenericMessage.h"

ConGenericMessage::ConGenericMessage(const String& msg) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x08C5FC76); // CRC

	insertAscii(msg); // Message to show in spatial chat box
	insertInt(0);	  //??

	setCompression(true);
}