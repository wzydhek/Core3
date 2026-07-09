#include "CancelTicketResponseMessage.h"

CancelTicketResponseMessage::CancelTicketResponseMessage(uint32 ticketid, bool success) : BaseMessage() {
	insertShort(0x03);
	insertInt(0xD6FBF318); // CRC

	if (success == true)
		insertInt(0);
	else
		insertInt(1);

	insertInt(ticketid); // ticketid.
}