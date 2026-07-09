/*
 * GuildTransferLeadershipSuiCallback.h
 *
 *  Created on: Oct 8, 2012
 *      Author: root
 */

#pragma once

//#include "server/zone/managers/guild/GuildManager.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sui/SuiBox.h"

class GuildTransferLeadershipSuiCallback : public SuiCallback {
public:
	GuildTransferLeadershipSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

};
