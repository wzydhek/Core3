
#pragma once

#include "engine/engine.h"
#include "server/zone/objects/guild/GuildObject.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/guild/GuildManager.h"

class RenameGuildTask : public Task {
	ZoneServer* server;

	ManagedWeakReference<GuildObject*> guildObject;

public:
	RenameGuildTask(ZoneServer* zserv, GuildObject* guildObj);

	void run();
};
