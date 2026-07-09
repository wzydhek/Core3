#include "StructureStatusSuiCallback.h"
#include "server/zone/managers/structure/StructureManager.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/Zone.h"

StructureStatusSuiCallback::StructureStatusSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void StructureStatusSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isListBox() || cancelPressed)
		return;

	ManagedReference<SceneObject*> obj = sui->getUsingObject().get();
	ManagedReference<StructureObject*> structure = sui->getStructureObject().get();

	if (obj == nullptr || creature == nullptr || structure == nullptr) {
		return;
	}

	Zone* zone = structure->getZone();

	if (zone == nullptr) {
		return;
	}

	GCWManager* gcwMan = zone->getGCWManager();

	if (gcwMan == nullptr) {
		return;
	}

	if ((structure->isGCWBase() && !gcwMan->canUseTerminals(creature, structure->asBuildingObject(), obj)) || !structure->isOnAdminList(creature)) {
		creature->sendSystemMessage("@player_structure:no_valid_structurestatus"); // Your /structureStatus target is no longer valid. Cancelling refresh.
		return;
	}

	StructureManager::instance()->reportStructureStatus(creature, structure, obj);
}