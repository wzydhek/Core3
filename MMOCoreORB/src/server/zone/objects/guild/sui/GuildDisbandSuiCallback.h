/*
 * GuildDisbandSuiCallback.h
 *
 *  Created on: Nov 3, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/managers/guild/GuildManager.h"
#include "server/zone/objects/tangible/terminal/guild/GuildTerminal.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sui/SuiBox.h"

namespace server {
namespace zone {
namespace objects {
namespace guild {
namespace sui {

class GuildDisbandSuiCallback : public SuiCallback {
public:
	GuildDisbandSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace guild
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::guild::sui;
