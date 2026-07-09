/*
 * GuildTransferLeaderAckSuiCallback.h
 *
 *  Created on: Oct 8, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/managers/guild/GuildManager.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/objects/tangible/terminal/guild/GuildTerminal.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sui/SuiBox.h"

class GuildTransferLeaderAckSuiCallback : public SuiCallback {
public:
	GuildTransferLeaderAckSuiCallback(ZoneServer* server);

	void run(CreatureObject* newLeader, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
