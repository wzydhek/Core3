#include "DestroyShipComponentMessage.h"

DestroyShipComponentMessage::DestroyShipComponentMessage(ShipObject* ship, int slot, float scale) : BaseMessage() {
	insertShort(0x12);
	insertInt(String::hashCode("DestroyShipComponentMessage"));
	insertLong(ship->getObjectID());
	insertInt(slot);
	insertFloat(scale);
}