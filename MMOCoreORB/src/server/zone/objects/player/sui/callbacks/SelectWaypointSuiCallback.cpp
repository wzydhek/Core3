#include "SelectWaypointSuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidMerchantModuleDataComponent.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

SelectWaypointSuiCallback::SelectWaypointSuiCallback(ZoneServer* serv, DroidMerchantModuleDataComponent* module) : SuiCallback(serv), module(module), slotIndex(0) {
}

void SelectWaypointSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || module == nullptr)
		return;

	if (cancelPressed) {
		return;
	}

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);
	ManagedReference<WaypointObject*> waypoint = server->getObject(listBox->getMenuObjectID(index)).castTo<WaypointObject*>();
	// If empty slot is configured, remove the configured effect
	if (waypoint != nullptr) {
		Locker dlock(module->getDroidObject(), player);
		module->setWaypoint(waypoint);
		player->sendSystemMessage("@pet/droid_modules:waypoint_set");
	}
}