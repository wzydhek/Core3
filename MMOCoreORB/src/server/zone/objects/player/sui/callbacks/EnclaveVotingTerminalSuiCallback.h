#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/frs/FrsManager.h"

class EnclaveVotingTerminalSuiCallback : public SuiCallback {
private:
	short suiType, enclaveType;
	int rank;
	bool selectingRank;
public:
	EnclaveVotingTerminalSuiCallback(ZoneServer* server, short type, short enclave, int rnk, bool selectRank);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
