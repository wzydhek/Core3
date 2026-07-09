#include "SlicingSessionSuiCallback.h"

SlicingSessionSuiCallback::SlicingSessionSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void SlicingSessionSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox())
		return;

	if (args->size() < 1)
		return;

	ManagedReference<Facade*> facade = player->getActiveSession(SessionFacadeType::SLICING);
	ManagedReference<SlicingSession*> session = dynamic_cast<SlicingSession*>(facade.get());

	if (session == nullptr) {
		ManagedReference<TangibleObject*> obj = cast<TangibleObject*>(suiBox->getUsingObject().get().get());

		if (obj != nullptr) {
			Locker crosslock(obj, player);
			obj->dropActiveSession(SessionFacadeType::SLICING);
		}

		return;
	}

	if (cancelPressed) {
		session->cancelSession();
		return;
	}

	int idx = Integer::valueOf(args->get(0).toString());

	SuiListBox* box = cast<SuiListBox*>(suiBox);

	byte menuID = box->getMenuObjectID(idx);

	session->handleMenuSelect(player, menuID, box);
}