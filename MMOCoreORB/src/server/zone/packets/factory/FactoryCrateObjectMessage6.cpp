#include "FactoryCrateObjectMessage6.h"

FactoryCrateObjectMessage6::FactoryCrateObjectMessage6(TangibleObject* tano) : BaseLineMessage(tano->getObjectID(), 0x46435954, 6, 0x06) {
	insertShort(3);

	insertInt(0);
	insertInt(0);

	insertInt(0);
	insertInt(0);

	insertInt(0);
	insertInt(0);

	insertInt(0);
	insertInt(0);

	insertByte(0);

	setSize();
}