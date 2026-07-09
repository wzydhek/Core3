#include "ChatOnRemoveModeratorFromRoom.h"
#include "server/zone/ZoneServer.h"

ChatOnRemoveModeratorFromRoom::ChatOnRemoveModeratorFromRoom(CreatureObject* deoper, const String& deopee, const String& roomPath, int error, int requestID) : BaseMessage() {
	String galaxy = deoper->getZoneServer()->getGalaxyName();

	insertShort(0x06);
	insertInt(0x1342FC47); // Opcode

	insertAscii("SWG");	 // Game
	insertAscii(galaxy); // Galaxy name
	insertAscii(deopee); // Deopee's first name

	insertAscii("SWG");					 // Game
	insertAscii(galaxy);				 // Galaxy name
	insertAscii(deoper->getFirstName()); // Deoper's first name

	insertInt(error);	   /// Result code
	insertAscii(roomPath); // Full room path
	insertInt(requestID);  // Request ID
}