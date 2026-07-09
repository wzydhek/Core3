#include "CreateTicketResponseMessage.h"

CreateTicketResponseMessage::CreateTicketResponseMessage(int unknown) : BaseMessage() {
	insertShort(0x09);
	insertInt(0x550A407A); // CRC

	insertInt(unknown);
}