#include "CloningRequestSuiCallback.h"

CloningRequestSuiCallback::CloningRequestSuiCallback(ZoneServer* server, int tod) : SuiCallback(server) {
	typeofdeath = tod;
}

void CloningRequestSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || player == nullptr || args->size() <= 0)
		return;

	SuiListBox* listbox = cast<SuiListBox*>(suiBox);

	int index = Integer::valueOf(args->get(0).toString());

	if (!player->isDead())
		return;

	if (index < 0 || index >= listbox->getMenuSize() || cancelPressed) {
		player->sendSystemMessage("You will remain dead until you choose a location to clone or you are revived. Type /activateClone to restore the cloning window.");
		return;
	}

	PlayerManager* playerManager = server->getPlayerManager();
	playerManager->sendPlayerToCloner(player, listbox->getMenuObjectID(index), typeofdeath);
}