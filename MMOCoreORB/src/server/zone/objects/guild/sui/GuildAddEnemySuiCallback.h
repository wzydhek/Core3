/*
 * GuildAddEnemySuiCallback.h
 *
 *  Created on: Jun 7, 2012
 *      Author: chris.rush
 */

#pragma once

#include "server/zone/managers/guild/GuildManager.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sui/SuiBox.h"

class GuildAddEnemySuiCallback : public SuiCallback {
	ManagedWeakReference<GuildObject*> guildObject;

public:
	GuildAddEnemySuiCallback(ZoneServer* server, GuildObject* guild);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
