#include "ChatOnReceiveRoomInvitation.h"

ChatOnReceiveRoomInvitation::ChatOnReceiveRoomInvitation(const String& galaxy, const String& moderator, const String& roomPath) : BaseMessage() {
	insertShort(0x03);
	insertInt(0xC17EB06D);	// Opcode
	insertAscii("SWG");		// Game
	insertAscii(galaxy);	// Galaxy
	insertAscii(moderator); // Moderator name
	insertAscii(roomPath);	// Chat room path
}