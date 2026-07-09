#include "CitySpecializationConfirmSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

CitySpecializationConfirmSuiCallback::CitySpecializationConfirmSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void CitySpecializationConfirmSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CitySpecializationSession*> session = player->getActiveSession(SessionFacadeType::CITYSPEC).castTo<CitySpecializationSession*>();

	if (session == nullptr)
		return;

	if (!suiBox->isMessageBox() || cancelPressed) {
		session->cancelSession();
		return;
	}

	session->acceptChoice();
}