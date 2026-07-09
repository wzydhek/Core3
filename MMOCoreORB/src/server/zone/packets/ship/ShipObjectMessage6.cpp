#include "ShipObjectMessage6.h"
#include "server/zone/packets/tangible/TangibleObjectMessage6.h"

ShipObjectMessage6::ShipObjectMessage6(ShipObject* ship) : BaseLineMessage(ship, 0x53484950, 6, 23) {
	insertInt(0x76); // 0x3D in creos

	ship->getDefenderList()->insertToMessage(this);

	insertShort(ship->getUniqueID());
	insertFloat(ship->getActualAccelerationRate());
	insertFloat(ship->getActualDecelerationRate());

	insertFloat(ship->getActualPitchAccelerationRate());
	insertFloat(ship->getActualYawAccelerationRate());
	insertFloat(ship->getActualRollAccelerationRate());

	insertFloat(ship->getActualPitchRate());
	insertFloat(ship->getActualYawRate());
	insertFloat(ship->getActualRollRate());
	insertFloat(ship->getActualMaxSpeed());

	insertLong(ship->getShipTargetID());
	insertInt(ship->getShipTargetSlot());

	ship->getTargetableBitfield()->insertToMessage(this);
	ship->getShipComponentMap()->insertToMessage(this);

	insertAscii(""); // wingName
	insertAscii(getShipTypeName(ship));
	insertAscii(ship->getShipDifficulty());
	insertAscii(ship->getShipFactionString());

	insertFloat(ship->getFrontShield());
	insertFloat(ship->getRearShield());

	insertInt(getGuildID(ship));

	setSize();
}

int ShipObjectMessage6::getGuildID(ShipObject* ship) {
	auto owner = ship->getOwner().get();
	return owner != nullptr && owner->isInGuild() ? owner->getGuildID() : 0;
}

String ShipObjectMessage6::getShipTypeName(ShipObject* ship) {
	if (ship->isShipAiAgent()) {
		return ship->getShipType();
	} else {
		return "";
	}
}