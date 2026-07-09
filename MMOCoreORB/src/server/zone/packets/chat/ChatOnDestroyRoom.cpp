#include "ChatOnDestroyRoom.h"

ChatOnDestroyRoom::ChatOnDestroyRoom(const String& game, const String& server, const String& owner, uint32 roomID, int errorCode, int requestID) : BaseMessage() {
	insertShort(0x05);
	insertInt(0xE8EC5877); // Opcode
	insertAscii(game);	   // Game
	insertAscii(server);   // Server
	insertAscii(owner);	   // Owner
	insertInt(errorCode);  // Error Code
	insertInt(roomID);	   // Room ID
	insertInt(requestID);  // Request ID
}

ChatOnDestroyRoom::ChatOnDestroyRoom(uint32 roomID, int errorCode, int requestID) : BaseMessage() {
	insertShort(0x05);
	insertInt(0xE8EC5877); // Opcode
	insertAscii("");	   // Game
	insertAscii("");	   // Server
	insertAscii("");	   // Owner
	insertInt(errorCode);  // Error Code
	insertInt(roomID);	   // Room ID
	insertInt(requestID);  // Request ID
}