#include "FactoryCrateObjectMessage3.h"

FactoryCrateObjectMessage3::FactoryCrateObjectMessage3(FactoryCrate* crate, uint32 objType, uint16 opcnt) : BaseLineMessage(crate->getObjectID(), objType, 3, opcnt) {
	insertFloat(1.0);

	insertStringId(crate->getObjectName());
	insertCustomName(crate->getCustomObjectName());

	insertInt(crate->getVolume());

	String app;
	crate->getCustomizationString(app);
	insertAscii(app);

	insertInt(0);
	insertInt(0);

	Reference<TangibleObject*> proto = crate->getPrototype();

	if (proto == nullptr)
		insertInt(crate->getOptionsBitmask());
	else
		insertInt(proto->getOptionsBitmask());

	int count = crate->getUseCount();

	insertInt(count); // item count

	insertInt(int(crate->getConditionDamage()));
	insertInt(crate->getMaxCondition());

	insertByte(crate->getObjectVisible());

	setSize();
}