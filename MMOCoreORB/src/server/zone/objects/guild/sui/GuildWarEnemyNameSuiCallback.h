/*
 * GuildWarEnemyNameSuiCallback.h
 *
 *  Created on: Jun 7, 2012
 *      Author: chris.rush
 */

#pragma once

#include "server/zone/managers/guild/GuildManager.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sui/SuiBox.h"

namespace server {
namespace zone {
namespace objects {
namespace guild {
namespace sui {

class GuildWarEnemyNameSuiCallback : public SuiCallback {
	ManagedWeakReference<GuildObject*> guildObject;

public:
	GuildWarEnemyNameSuiCallback(ZoneServer* server, GuildObject* guild);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace guild
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::guild::sui;
