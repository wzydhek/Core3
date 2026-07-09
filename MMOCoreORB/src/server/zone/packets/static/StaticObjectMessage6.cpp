#include "StaticObjectMessage6.h"

StaticObjectMessage6::StaticObjectMessage6(StaticObject* stao) : BaseLineMessage(stao->getObjectID(), 0x4F415453, 6, 2) {
	insertInt(0x44);
	insertAscii("String_id_table");
	insertInt(0);
	insertShort(0);

	setSize();
}