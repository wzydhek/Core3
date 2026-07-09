#include "NameVendorSuiCallback.h"

NameVendorSuiCallback::NameVendorSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void NameVendorSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isInputBox())
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

	String name = args->get(0).toString();

	session->createVendor(name);
}