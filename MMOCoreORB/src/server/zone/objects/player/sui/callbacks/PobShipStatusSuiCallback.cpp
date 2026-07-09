#include "PobShipStatusSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/managers/ship/ShipManager.h"

PobShipStatusSuiCallback::PobShipStatusSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void PobShipStatusSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isListBox() || cancelPressed)
		return;

	ManagedReference<SceneObject*> sceneO = sui->getUsingObject().get();
	ManagedReference<PobShipObject*> pobShip = sui->getPobShipObject().get();

	if (sceneO == nullptr || creature == nullptr || pobShip == nullptr) {
		return;
	}

	Zone* zone = pobShip->getZone();

	if (zone == nullptr || !zone->isSpaceZone()) {
		return;
	}

	if (!pobShip->isOnAdminList(creature)) {
		creature->sendSystemMessage("@player_structure:no_valid_structurestatus"); // Your /structureStatus target is no longer valid. Cancelling refresh.
		return;
	}

	ShipManager::instance()->reportPobShipStatus(creature, pobShip, sceneO);
}