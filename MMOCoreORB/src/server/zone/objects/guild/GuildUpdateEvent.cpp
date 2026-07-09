#include "GuildUpdateEvent.h"

GuildUpdateEvent::GuildUpdateEvent(GuildObject* guildObj, ZoneServer* zserv) : Task() {
	guildObject = guildObj;

	server = zserv;

	setCustomTaskQueue("slowQueue");
}

void GuildUpdateEvent::run() {
	if (server == nullptr || server->isServerShuttingDown())
		return;

	ManagedReference<GuildObject*> guild = guildObject.get();

	if (guild == nullptr)
		return;

	Locker locker(guild);

	if (server->isServerLoading()) {
		guild->rescheduleUpdateEvent(10000);
		return;
	}

	GuildManager* guildManager = server->getGuildManager();

	guildManager->processGuildUpdate(guild);
}