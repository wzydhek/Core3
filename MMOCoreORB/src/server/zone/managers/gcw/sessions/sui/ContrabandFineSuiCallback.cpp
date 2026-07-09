#include "ContrabandFineSuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

ContrabandFineSuiCallback::ContrabandFineSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void ContrabandFineSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool acceptedFine = (eventIndex != 1);

	if (player != nullptr) {
		ManagedReference<ContrabandScanSession*> scanSession = player->getActiveSession(SessionFacadeType::CONTRABANDSCAN).castTo<ContrabandScanSession*>();
		if (scanSession != nullptr) {
			scanSession->setAcceptFineAnswer(acceptedFine);
		}
	}
}