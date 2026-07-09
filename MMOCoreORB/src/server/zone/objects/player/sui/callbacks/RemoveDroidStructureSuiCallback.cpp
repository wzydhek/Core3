#include "RemoveDroidStructureSuiCallback.h"

RemoveDroidStructureSuiCallback::RemoveDroidStructureSuiCallback(ZoneServer* serv, DroidMaintenanceModuleDataComponent* module) : SuiCallback(serv) {
	this->module = module;
}

void RemoveDroidStructureSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || module == nullptr)
		return;

	if (cancelPressed)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);
	uint64 itemId = listBox->getMenuObjectID(index);

	Locker dlock(module->getDroidObject(), player);
	module->unassignStructure(itemId);
}