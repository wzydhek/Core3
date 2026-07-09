#include "CloseHolocronMessage.h"

CloseHolocronMessage::CloseHolocronMessage() : BaseMessage() {
	insertShort(0x01);
	insertInt(0xC0938A9D); // CRC

	// Closes the Holocron Screen.
}