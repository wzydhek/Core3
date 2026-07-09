#include "GuildObjectMessage6.h"

GuildObjectMessage6::GuildObjectMessage6(uint64 oid) : BaseLineMessage(oid, 0x47494C44, 6, 0x01) {
	insertInt(0x3B);

	setSize();
}