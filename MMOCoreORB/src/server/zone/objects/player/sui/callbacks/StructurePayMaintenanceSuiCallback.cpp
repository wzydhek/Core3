#include "StructurePayMaintenanceSuiCallback.h"
#include "server/zone/objects/player/sui/transferbox/SuiTransferBox.h"
#include "server/zone/Zone.h"

StructurePayMaintenanceSuiCallback::StructurePayMaintenanceSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void StructurePayMaintenanceSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isTransferBox() || cancelPressed || args->size() < 2)
		return;

	int amount = Integer::valueOf(args->get(1).toString());

	if (amount < 0)
		return;

	ManagedReference<SceneObject*> obj = sui->getUsingObject().get();

	if (obj == nullptr || !obj->isStructureObject()) {
		creature->sendSystemMessage("@player_structure:invalid_target"); // "Your original structure target is no longer valid. Aborting..."
		return;
	}

	// Deposit/Withdraw the maintenance
	StructureObject* structure = cast<StructureObject*>(obj.get());

	ManagedReference<Zone*> zone = structure->getZone();

	if (zone == nullptr)
		return;

	// Creature is already locked (done in handleSuiEventNotification in SuiManager).
	Locker _lock(structure, creature);

	StructureManager::instance()->payMaintenance(structure, creature, amount);
}