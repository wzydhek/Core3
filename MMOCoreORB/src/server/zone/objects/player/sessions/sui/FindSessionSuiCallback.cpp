#include "FindSessionSuiCallback.h"

FindSessionSuiCallback::FindSessionSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void FindSessionSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox())
		return;

	ManagedReference<Facade*> facade = player->getActiveSession(SessionFacadeType::FIND);
	ManagedReference<FindSession*> session = dynamic_cast<FindSession*>(facade.get());

	if (session == nullptr) {
		ManagedReference<CreatureObject*> pl = cast<CreatureObject*>(suiBox->getUsingObject().get().get());

		if (pl != nullptr)
			pl->dropActiveSession(SessionFacadeType::FIND);

		return;
	}

	if (cancelPressed) {
		session->cancelSession();
		return;
	}

	if (args->size() < 1) {
		session->cancelSession();

		return;
	}

	int index = Integer::valueOf(args->get(0).toString());

	if (index == -1) {
		session->cancelSession();
		return;
	}

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);

	String mapCategory = listBox->getMenuItemName(index).subString(14);
	String mapSubCategory;

	if (mapCategory.contains("_")) {
		StringTokenizer tokenizer(mapCategory);
		tokenizer.setDelimeter("_");

		mapSubCategory = mapCategory;
		mapCategory = tokenizer.getStringToken();
	}

	// player->info(true) << "Map Category = " << mapCategory << " Map Sub Category = " << mapSubCategory;

	session->findPlanetaryObject(mapCategory, mapSubCategory);
}