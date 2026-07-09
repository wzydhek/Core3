#include "ConfirmDivorceSuiCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

ConfirmDivorceSuiCallback::ConfirmDivorceSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void ConfirmDivorceSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	PlayerManager* playerManager = creature->getZoneServer()->getPlayerManager();
	if (playerManager == nullptr)
		return;

	if (!cancelPressed) {
		playerManager->grantDivorce(creature);
	}
}