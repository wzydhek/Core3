#include "EnclaveCouncilRankSuiCallback.h"

EnclaveCouncilRankSuiCallback::EnclaveCouncilRankSuiCallback(ZoneServer* server, int type) : SuiCallback(server) {
	councilType = type;
}

void EnclaveCouncilRankSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed || player == nullptr)
		return;

	FrsManager* frsMan = player->getZoneServer()->getFrsManager();

	if (frsMan == nullptr)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	if (index < 0)
		return;

	frsMan->sendRankPlayerList(player, councilType, index + 1);
}