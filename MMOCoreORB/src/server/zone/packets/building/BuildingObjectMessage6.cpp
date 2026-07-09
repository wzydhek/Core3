#include "BuildingObjectMessage6.h"

BuildingObjectMessage6::BuildingObjectMessage6(BuildingObject *buio) : BaseLineMessage(buio->getObjectID(), 0x4255494F, 6, 0x02) {
	insertInt(0x42);

	insertInt(0); // Counter of uint64's
	insertInt(0); // Update count I assume.

	setSize();
}