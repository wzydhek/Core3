/*
 * UpdateWarStatusTask.h
 *
 *  Created on: Jun 8, 2012
 *      Author: swgemu
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/guild/GuildObject.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/chat/ChatManager.h"

namespace server {
namespace zone {
namespace objects {
namespace guild {

class UpdateWarStatusTask : public Task {
	ZoneServer* server;

	GuildMemberList guild1;
	GuildMemberList guild2;

public:
	UpdateWarStatusTask(ZoneServer* zserv, GuildObject* guild, GuildObject* waringGuild);

	void run();
};

} // namespace guild
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::guild;
