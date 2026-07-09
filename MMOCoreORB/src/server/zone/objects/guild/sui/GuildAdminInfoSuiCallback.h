
#pragma once

#include "server/zone/managers/guild/GuildManager.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sui/SuiBox.h"

class GuildAdminInfoSuiCallback : public SuiCallback {
	ManagedWeakReference<GuildObject*> guildObject;

public:
	GuildAdminInfoSuiCallback(ZoneServer* server, GuildObject* guild);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
