#include "GuildObjectMessage3.h"

GuildObjectMessage3::GuildObjectMessage3(DeltaSet<String, ManagedReference<GuildObject*>>* guildList, uint64 oid) : BaseLineMessage(oid, 0x47494C44, 3, 0x05) {
	insertFloat(1);
	insertAscii("String_id_table");
	insertInt(0);
	insertAscii("");
	insertUnicode("");
	insertInt(0);

	guildList->insertToMessage(this);

	setSize();
}