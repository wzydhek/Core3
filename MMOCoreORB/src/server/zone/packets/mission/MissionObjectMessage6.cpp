#include "MissionObjectMessage6.h"

MissionObjectMessage6::MissionObjectMessage6(MissionObject* mi) : BaseLineMessage(mi->getObjectID(), 0x4D49534F, 6, 0x02) {
	insertInt(0x79);
	/*insertLong(0);
	insertLong(0);
	insertLong(0);
	insertLong(0);
	insertLong(0);
	insertLong(0);*/

	setSize();
}