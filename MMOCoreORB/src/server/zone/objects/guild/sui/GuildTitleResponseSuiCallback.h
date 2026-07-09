/*
 * GuildMemberTitleCallback.h
 *
 *  Created on: Nov 4, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/managers/guild/GuildManager.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sui/SuiBox.h"

class GuildTitleResponseSuiCallback : public SuiCallback {
public:
	GuildTitleResponseSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
