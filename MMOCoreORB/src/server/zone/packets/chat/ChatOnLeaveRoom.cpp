#include "ChatOnLeaveRoom.h"

ChatOnLeaveRoom::ChatOnLeaveRoom(ChatRoom* room, CreatureObject* player) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x60B5098B); // Opcode

	insertAscii("SWG");
	insertAscii(room->getGalaxyName());
	insertAscii(player->getFirstName());

	insertInt(0);				  // Error Code
	insertInt(room->getRoomID()); // Room ID
	insertInt(0);				  // Request ID. Always seen 0.
}