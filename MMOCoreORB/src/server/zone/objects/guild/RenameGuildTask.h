
#pragma once

#include "engine/engine.h"
#include "server/zone/objects/guild/GuildObject.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/guild/GuildManager.h"

namespace server {
namespace zone {
namespace objects {
namespace guild {

class RenameGuildTask : public Task {
	ZoneServer* server;

	ManagedWeakReference<GuildObject*> guildObject;

public:
	RenameGuildTask(ZoneServer* zserv, GuildObject* guildObj);

	void run();
};

} // namespace guild
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::guild;
