#include "GamblingSlotSuiCallback.h"
#include "server/zone/ZoneProcessServer.h"
#include "server/zone/objects/tangible/terminal/gambling/GamblingTerminal.h"

GamblingSlotSuiCallback::GamblingSlotSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GamblingSlotSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || player == nullptr)
		return;

	if (args->size() < 1)
		return;

	bool otherPressed = Bool::valueOf(args->get(0).toString());

	GamblingManager* manager = player->getZoneProcessServer()->getGamblingManager();

	Locker locker(manager);
	manager->handleSlot(player, cancelPressed, otherPressed);
}