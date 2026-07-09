#include "RenameGuildTask.h"

RenameGuildTask::RenameGuildTask(ZoneServer* zserv, GuildObject* guildObj) : Task() {
	guildObject = guildObj;

	server = zserv;
}

void RenameGuildTask::run() {
	ManagedReference<GuildObject*> guild = guildObject.get();

	if (guild == nullptr || !guild->isRenamePending())
		return;

	Locker locker(guild);

	ManagedReference<GuildManager*> guildManager = server->getGuildManager();
	if (guildManager == nullptr) {
		guild->resetRename();
		return;
	}

	guildManager->renameGuild(guild);
}