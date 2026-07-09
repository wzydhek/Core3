#include "GuildResponseMessage.h"
#include "server/zone/objects/guild/GuildObject.h"

GuildResponseMessage::GuildResponseMessage(CreatureObject* creo) : BaseMessage() {
	insertShort(0x04);
	insertInt(0x32263F20); // CRC

	insertLong(creo->getObjectID()); // Object Id to set guild for

	ManagedReference<GuildObject*> guild = creo->getGuildObject().get();

	if (guild == nullptr)
		insertAscii("");
	else
		insertAscii(guild->getGuildName());

	insertShort(0);

	setCompression(true);
}