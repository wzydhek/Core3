#include "SelectHarvestTypeSuiCallback.h"

SelectHarvestSuiCallback::SelectHarvestSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void SelectHarvestSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || cancelPressed != 0) {
		return;
	}

	if (args->size() < 1) {
		return;
	}

	int index = Integer::valueOf(args->get(0).toString());

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);
	ManagedReference<SceneObject*> object = suiBox->getUsingObject().get();

	if (object == nullptr) {
		return;
	}

	DroidObject* droid = cast<DroidObject*>(object.get());
	if (droid == nullptr) {
		return;
	}

	auto module = droid->getModule("harvest_module").castTo<DroidHarvestModuleDataComponent*>();

	if (module == nullptr) {
		return;
	}

	Locker crosslock(droid, player);

	module->setHarvestInterest(player, index);
}