#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/frs/FrsManager.h"

class EnclaveCouncilRankSuiCallback : public SuiCallback {
private:
	int councilType;
public:
	EnclaveCouncilRankSuiCallback(ZoneServer* server, int type);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
