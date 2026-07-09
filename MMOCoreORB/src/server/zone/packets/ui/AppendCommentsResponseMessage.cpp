#include "AppendCommentsResponseMessage.h"

AppendCommentsResponseMessage::AppendCommentsResponseMessage(uint32 ticketid, bool success) : BaseMessage() {
	insertShort(0x03);
	insertInt(0xA04A3ECA); // CRC

	if (success == true)
		insertInt(0);
	else
		insertInt(1);

	insertInt(ticketid); // ticketid.
}