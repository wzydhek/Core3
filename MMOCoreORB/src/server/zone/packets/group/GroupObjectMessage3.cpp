#include "GroupObjectMessage3.h"
#include "server/zone/objects/creature/CreatureObject.h"

GroupObjectMessage3::GroupObjectMessage3(GroupObject* grup) : BaseLineMessage(grup->getObjectID(), 'GRUP', 0x03, 0x05) {
	// info(true) << "GroupObjectMessage3 called";
	insertFloat(1);

	insertAscii("string_id_table");

	insertInt(0x0);
	insertShort(0x0);
	insertInt(0x0);
	insertInt(0x0);

	insertFloat(1);

	setSize();
}