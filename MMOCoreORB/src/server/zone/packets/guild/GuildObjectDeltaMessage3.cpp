#include "GuildObjectDeltaMessage3.h"

GuildObjectDeltaMessage3::GuildObjectDeltaMessage3(uint64 oid) : DeltaMessage(oid, 0x47494C44, 3) {
}

void GuildObjectDeltaMessage3::addGuild(GuildObject* guild) {
	startUpdate(0x04);
	startList(1, 0);
	insertByte(0x01);

	if (guild == nullptr) {
		insertAscii("");
		return;
	}

	StringBuffer guildString;
	guildString << guild->getGuildID() << ":" << guild->getGuildAbbrev();
	insertAscii(guildString.toString());
}

void GuildObjectDeltaMessage3::removeGuild(GuildObject* guild) {
	startUpdate(0x04);
	startList(1, 0);
	insertByte(0x00);

	if (guild == nullptr) {
		insertAscii("");
		return;
	}

	StringBuffer guildString;
	guildString << guild->getGuildID() << ":" << guild->getGuildAbbrev();
	insertAscii(guildString.toString());
}

void GuildObjectDeltaMessage3::removeAllGuilds() {
	startUpdate(0x04);
	insertInt(0);
	insertInt(0);
	insertByte(0x03);
}