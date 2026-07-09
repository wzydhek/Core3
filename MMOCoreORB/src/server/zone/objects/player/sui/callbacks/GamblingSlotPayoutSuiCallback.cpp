#include "GamblingSlotPayoutSuiCallback.h"
#include "server/zone/objects/tangible/terminal/gambling/GamblingTerminal.h"

GamblingSlotPayoutSuiCallback::GamblingSlotPayoutSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GamblingSlotPayoutSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	if (!suiBox->isListBox() || player == nullptr)
		return;

	player->sendMessage(suiBox->generateCloseMessage());
}