#include "ClientMfdStatusUpdateMessage.h"
#include "server/zone/Zone.h"

ClientMfdStatusUpdateMessage::ClientMfdStatusUpdateMessage() : BaseMessage() {
	insertShort(0x06);
	insertInt(0x2D2D6EE1); // CRC
}

ClientMfdStatusUpdateMessage::ClientMfdStatusUpdateMessage(SceneObject* sceno) : BaseMessage() {
	insertShort(0x06);
	insertInt(0x2D2D6EE1); // CRC
	insertAscii(sceno->getZone()->getZoneName());
	insertLong(sceno->getObjectID());
	insertFloat(sceno->getWorldPositionX()); // x
	insertFloat(sceno->getWorldPositionZ()); // z
	insertFloat(sceno->getWorldPositionY()); // y
}

ClientMfdStatusUpdateMessage::ClientMfdStatusUpdateMessage(SceneObject* sceno, const String& planet) : BaseMessage() {
	insertShort(0x06);
	insertInt(0x2D2D6EE1); // CRC
	insertAscii(planet);
	insertLong(sceno->getObjectID());
	insertFloat(sceno->getWorldPositionX()); // x
	insertFloat(sceno->getWorldPositionZ()); // z
	insertFloat(sceno->getWorldPositionY()); // y
}

void ClientMfdStatusUpdateMessage::UpdateMember(SceneObject* cr, const String& planet) {
	// Updates player info on other planets.
	insertAscii(planet);				  // Planet name
	insertLong(cr->getObjectID());		  // Object id
	insertFloat(cr->getWorldPositionX()); // x
	insertFloat(cr->getWorldPositionZ()); // z
	insertFloat(cr->getWorldPositionY()); // y
}