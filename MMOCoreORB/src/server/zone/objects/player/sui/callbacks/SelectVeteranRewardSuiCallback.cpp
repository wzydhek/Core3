#include "SelectVeteranRewardSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/managers/player/PlayerManager.h"

SelectVeteranRewardSuiCallback::SelectVeteranRewardSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void SelectVeteranRewardSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	PlayerManager* playerManager = player->getZoneServer()->getPlayerManager();
	if (!suiBox->isListBox() || playerManager == nullptr)
		return;

	if (cancelPressed) {
		playerManager->cancelVeteranRewardSession(player);
		return;
	}

	if (args->size() < 1) {
		playerManager->cancelVeteranRewardSession(player);
		return;
	}

	int index = Integer::valueOf(args->get(0).toString());

	if (index < 0) {
		playerManager->cancelVeteranRewardSession(player);
		return;
	}

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);
	uint64 itemId = listBox->getMenuObjectID(index);

	// Confirm selection
	playerManager->confirmVeteranReward(player, itemId);
}