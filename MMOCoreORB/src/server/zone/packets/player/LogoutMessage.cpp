#include "LogoutMessage.h"

LogoutMessage::LogoutMessage() : BaseMessage() {
	insertShort(0x01);
	insertInt(0x42FD19DD); // CRC

	// Logs out the player.
}