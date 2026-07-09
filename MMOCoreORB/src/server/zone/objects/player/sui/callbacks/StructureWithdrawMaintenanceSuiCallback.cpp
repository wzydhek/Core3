#include "StructureWithdrawMaintenanceSuiCallback.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"
#include "server/zone/Zone.h"

StructureWithdrawMaintenanceSuiCallback::StructureWithdrawMaintenanceSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void StructureWithdrawMaintenanceSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isInputBox() || cancelPressed || args->size() < 1)
		return;

	int amount = Integer::valueOf(args->get(0).toString());

	if (amount < 0)
		return;

	ManagedReference<SceneObject*> obj = sui->getUsingObject().get();

	if (obj == nullptr || !obj->isStructureObject())
		return;

	// Withdraw the maintenance
	StructureObject* structure = cast<StructureObject*>(obj.get());

	ManagedReference<Zone*> zone = structure->getZone();

	if (zone == nullptr)
		return;

	// Creature is already locked (done in handleSuiEventNotification in SuiManager).
	Locker _lock(structure, creature);

	StructureManager::instance()->withdrawMaintenance(structure, creature, amount);
}