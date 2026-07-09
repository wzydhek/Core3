#include "ShipObjectMessage4.h"

ShipObjectMessage4::ShipObjectMessage4(ShipObject* ship) : BaseLineMessage(ship->getObjectID(), 0x53484950, 4, 5) {
	insertFloat(ship->getChassisMass());
	insertFloat(ship->getChassisSpeed());

	insertFloat(ship->getCapacitorEnergy());
	insertFloat(ship->getBoosterEnergy());

	ship->getComponentRefireEfficiency()->insertToMessage(this);

	setSize();
}