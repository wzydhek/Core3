
#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "templates/faction/Factions.h"
#include "server/zone/objects/creature/CreatureObject.h"

class SurrenderPilotSuiCallback : public SuiCallback {
	uint32 faction;

public:
	SurrenderPilotSuiCallback(ZoneServer* server, uint32 factionHash);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
