#include "FactionResponseMessage.h"

FactionResponseMessage::FactionResponseMessage(FactionStandingList* fpl) : BaseMessage() {
	insertShort(0x07);
	insertInt(0x5DD53957); // CRC

	fpl->insertToMessage(this);

	setCompression(true);
}