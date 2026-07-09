#include "GamblingRouletteSuiCallback.h"
#include "server/zone/ZoneProcessServer.h"
#include "server/zone/objects/tangible/terminal/gambling/GamblingTerminal.h"

GamblingRouletteSuiCallback::GamblingRouletteSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GamblingRouletteSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || player == nullptr)
		return;

	GamblingManager* manager = player->getZoneProcessServer()->getGamblingManager();

	Locker locker(manager);

	if (cancelPressed)
		manager->leaveTerminal(player, 0);
	else
		manager->refreshRouletteMenu(player);
}