#include "ChatOnUnbanFromRoom.h"
#include "server/zone/ZoneServer.h"

ChatOnUnbanFromRoom::ChatOnUnbanFromRoom(CreatureObject* unbanner, const String& unbaneeName, const String& roomPath, int error, int requestID) : BaseMessage() {
	String galaxy = unbanner->getZoneServer()->getGalaxyName();

	insertShort(0x06);
	insertInt(0xBAF9B815); // Opcode

	insertAscii(roomPath); // Full room path

	insertAscii("SWG");					   // Game
	insertAscii(galaxy);				   // Galaxy name
	insertAscii(unbanner->getFirstName()); // Unbanner's first name

	insertAscii("SWG");		  // Game
	insertAscii(galaxy);	  // Galaxy name
	insertAscii(unbaneeName); // Unbanee's first name

	insertInt(error);	  /// Result code
	insertInt(requestID); // Request ID
}