#include "UpdateMissileMessage.h"

UpdateMissileMessage::UpdateMissileMessage(ShipObject* ship, const ShipProjectile* projectile, int countermeasureType, int updateType) : BaseMessage() {
	insertShort(0x14);
	insertInt(String::hashCode("UpdateMissileMessage"));

	insertInt(projectile->getUniqueID());
	insertLong(ship->getObjectID());
	insertInt(countermeasureType);
	insertInt(updateType);
}