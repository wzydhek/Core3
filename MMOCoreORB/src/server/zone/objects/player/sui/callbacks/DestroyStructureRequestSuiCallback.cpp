#include "DestroyStructureRequestSuiCallback.h"

DestroyStructureRequestSuiCallback::DestroyStructureRequestSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void DestroyStructureRequestSuiCallback::run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<DestroyStructureSession*> session = player->getActiveSession(SessionFacadeType::DESTROYSTRUCTURE).castTo<DestroyStructureSession*>();

	if (session == nullptr)
		return;

	if (cancelPressed) {
		session->cancelSession();
		return;
	}

	session->sendDestroyCode();
}