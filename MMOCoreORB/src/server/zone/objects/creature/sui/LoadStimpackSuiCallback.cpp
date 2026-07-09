#include "LoadStimpackSuiCallback.h"

LoadStimpackSuiCallback::LoadStimpackSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void LoadStimpackSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || cancelPressed != 0) {
		return;
	}

	if (args->size() < 1) {
		player->sendSystemMessage("@pet/droid_modules:invalid_stimpack");
		return;
	}

	int index = Integer::valueOf(args->get(0).toString());

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);
	ManagedReference<StimPack*> stimpack = server->getObject(listBox->getMenuObjectID(index)).castTo<StimPack*>();
	ManagedReference<SceneObject*> object = suiBox->getUsingObject().get();
	if (stimpack == nullptr) {
		player->sendSystemMessage("@pet/droid_modules:invalid_stimpack");
		return;
	}
	if (object == nullptr) {
		return;
	}

	DroidObject* droid = cast<DroidObject*>(object.get());
	if (droid == nullptr) {
		return;
	}

	auto module = droid->getModule("stimpack_module").castTo<DroidStimpackModuleDataComponent*>();
	if (module == nullptr) {
		return;
	}

	Locker locker(player);
	Locker clocker(player, droid);

	if (stimpack->isRangedStimPack()) {
		player->sendSystemMessage("@pet/droid_modules:invalid_stimpack");
		return;
	}
	module->handleInsertStimpack(player, stimpack);
}