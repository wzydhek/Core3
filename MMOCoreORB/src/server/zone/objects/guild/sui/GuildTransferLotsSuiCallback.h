/*
 * GuildTransferLotsSuiCallback.h
 *
 *  Created on: Oct 9, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/managers/guild/GuildManager.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/terminal/guild/GuildTerminal.h"

namespace server {
namespace zone {
namespace objects {
namespace guild {
namespace sui {

class GuildTransferLotsSuiCallback : public SuiCallback {
public:
	GuildTransferLotsSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

};

} // namespace sui
} // namespace guild
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::guild::sui;
