#include "StructureSetAccessDurationSuiCallback.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"
#include "server/zone/objects/player/sessions/StructureSetAccessFeeSession.h"

StructureSetAccessDurationSuiCallback::StructureSetAccessDurationSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void StructureSetAccessDurationSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isInputBox() || cancelPressed || args->size() < 1)
		return;

	ManagedReference<StructureSetAccessFeeSession*> session = creature->getActiveSession(SessionFacadeType::SETSTRUCTUREACCESSFEE).castTo<StructureSetAccessFeeSession*>();

	if (session == nullptr)
		return;

	try {
		int duration = Integer::valueOf(args->get(0).toString());

		if (duration >= 15 && duration <= 60 * 48)
			session->setAccessDuration(duration);
		else
			session->promptSetAccessDuration();
	} catch (Exception& e) {
		session->promptSetAccessDuration();
	}
}