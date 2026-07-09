#include "ProposeUnitySuiCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

ProposeUnitySuiCallback::ProposeUnitySuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void ProposeUnitySuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	PlayerManager* playerManager = creature->getZoneServer()->getPlayerManager();
	if (playerManager == nullptr)
		return;

	if (cancelPressed) {
		playerManager->denyUnity(creature);
	} else {
		playerManager->acceptUnity(creature);
	}
}