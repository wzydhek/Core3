
#pragma once

#include "engine/engine.h"
#include "server/zone/objects/guild/GuildObject.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/guild/GuildManager.h"

namespace server {
namespace zone {
namespace objects {
namespace guild {

class GuildUpdateEvent : public Task {
	ZoneServer* server;

	ManagedWeakReference<GuildObject*> guildObject;

public:
	GuildUpdateEvent(GuildObject* guildObj, ZoneServer* zserv);

	void run();
};

}
}
}
}

using namespace server::zone::objects::guild;
