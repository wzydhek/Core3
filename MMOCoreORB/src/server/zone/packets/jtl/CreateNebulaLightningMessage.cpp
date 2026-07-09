#include "CreateNebulaLightningMessage.h"
#include "server/zone/packets/ship/PackedPosition.h"

CreateNebulaLightningMessage::CreateNebulaLightningMessage(uint16 lightningCount, int nebulaID, int startMili, int endMili, Vector3 startPoint, Vector3 endPoint) : BaseMessage() {
	insertShort(0xB);
	insertInt(STRING_HASHCODE("CreateNebulaLightningMessage")); // CRC

	insertShort(lightningCount); // Lightning ID
	insertInt(nebulaID);		 // Nebula #

	insertInt(startMili); // Timestamp start
	insertInt(endMili);	  // Timestamp end

	startPoint.toBinaryStream(this);

	endPoint.toBinaryStream(this);
}