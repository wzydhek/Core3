#include "IntangibleObjectMessage6.h"

IntangibleObjectMessage6::IntangibleObjectMessage6(IntangibleObject* itno) : BaseLineMessage(itno->getObjectID(), 0x4F4E5449, 6, 2) {
	insertInt(0x6E);

	// Object controlled name ("monster_detail", "_n" and "_name") or droid command name for modules
	insertAscii(itno->getItemIdentifier());

	insertCustomName(itno->getDetailedDescription());

	setSize();
}