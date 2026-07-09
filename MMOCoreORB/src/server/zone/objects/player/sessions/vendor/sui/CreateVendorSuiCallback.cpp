#include "CreateVendorSuiCallback.h"

CreateVendorSuiCallback::CreateVendorSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void CreateVendorSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox())
		return;

	if (args->size() < 1)
		return;

	ManagedReference<Facade*> facade = player->getActiveSession(SessionFacadeType::CREATEVENDOR);
	ManagedReference<CreateVendorSession*> session = dynamic_cast<CreateVendorSession*>(facade.get());

	if (session == nullptr)
		return;

	if (cancelPressed) {
		session->cancelSession();
		return;
	}

	int idx = Integer::valueOf(args->get(0).toString());
	SuiListBox* box = cast<SuiListBox*>(suiBox);
	byte menuID = box->getMenuObjectID(idx);

	session->handleVendorSelection(menuID);
}