#include "SurveyDroidSessionSuiCallback.h"
#include "server/zone/objects/player/sessions/InterplanetarySurveyDroidSession.h"

SurveyDroidSessionSuiCallback::SurveyDroidSessionSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void SurveyDroidSessionSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox())
		return;

	if (args->size() < 1)
		return;

	ManagedReference<Facade*> facade = player->getActiveSession(SessionFacadeType::INTERPLANETARYSURVEYDROID);
	ManagedReference<InterplanetarySurveyDroidSession*> session = dynamic_cast<InterplanetarySurveyDroidSession*>(facade.get());

	if (session == nullptr) {
		ManagedReference<TangibleObject*> obj = cast<TangibleObject*>(suiBox->getUsingObject().get().get());
		if (obj != nullptr) {
			Locker crosslock(obj, player);
			obj->dropActiveSession(SessionFacadeType::INTERPLANETARYSURVEYDROID);
		}
		return;
	}

	if (cancelPressed) {
		session->cancelSession();
		return;
	}

	uint64 idx = Long::unsignedvalueOf(args->get(0).toString());
	SuiListBox* box = cast<SuiListBox*>(suiBox);
	session->handleMenuSelect(player, idx, box);
}