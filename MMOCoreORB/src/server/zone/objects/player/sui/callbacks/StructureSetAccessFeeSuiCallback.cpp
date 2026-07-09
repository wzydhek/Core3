#include "StructureSetAccessFeeSuiCallback.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"
#include "server/zone/objects/player/sessions/StructureSetAccessFeeSession.h"

StructureSetAccessFeeSuiCallback::StructureSetAccessFeeSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void StructureSetAccessFeeSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isInputBox() || cancelPressed || args->size() < 1)
		return;

	ManagedReference<StructureSetAccessFeeSession*> session = creature->getActiveSession(SessionFacadeType::SETSTRUCTUREACCESSFEE).castTo<StructureSetAccessFeeSession*>();

	if (session == nullptr)
		return;

	try {
		int fee = Integer::valueOf(args->get(0).toString());

		if (fee > 0 && fee <= 50000)
			session->setAccessFee(fee);
		else
			session->promptSetAccessFee();
	} catch (Exception& e) {
		session->promptSetAccessFee();
	}
}