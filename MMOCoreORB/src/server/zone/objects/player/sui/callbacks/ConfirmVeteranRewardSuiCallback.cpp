#include "ConfirmVeteranRewardSuiCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

ConfirmVeteranRewardSuiCallback::ConfirmVeteranRewardSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void ConfirmVeteranRewardSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	PlayerManager* playerManager = player->getZoneServer()->getPlayerManager();
	if (!suiBox->isMessageBox() || playerManager == nullptr)
		return;

	if (cancelPressed) {
		playerManager->cancelVeteranRewardSession(player);
		return;
	}

	// Generate reward
	playerManager->generateVeteranReward(player);
}