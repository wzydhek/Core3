#include "CitySpecializationSuiCallback.h"

CitySpecializationSuiCallback::CitySpecializationSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void CitySpecializationSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CitySpecializationSession*> session = player->getActiveSession(SessionFacadeType::CITYSPEC).castTo<CitySpecializationSession*>();

	if (session == nullptr)
		return;

	if (!suiBox->isListBox() || cancelPressed || args->size() <= 0) {
		session->cancelSession();
		return;
	}

	int index = Integer::valueOf(args->get(0).toString());

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);

	if (index < 0 || index > listBox->getMenuSize()) {
		session->cancelSession();
		return;
	}

	String choice = listBox->getMenuItemName(index);
	session->sendConfirmationBox(choice);
}