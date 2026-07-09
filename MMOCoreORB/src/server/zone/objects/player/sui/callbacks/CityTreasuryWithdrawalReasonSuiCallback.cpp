#include "CityTreasuryWithdrawalReasonSuiCallback.h"

CityTreasuryWithdrawalReasonSuiCallback::CityTreasuryWithdrawalReasonSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void CityTreasuryWithdrawalReasonSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityTreasuryWithdrawalSession*> session = player->getActiveSession(SessionFacadeType::CITYWITHDRAW).castTo<CityTreasuryWithdrawalSession*>();

	if (session == nullptr)
		return;

	if (!suiBox->isInputBox() || cancelPressed || args->size() <= 0) {
		session->cancelSession();
		return;
	}

	String reason = args->get(0).toString();
	session->sendTransferBox(reason);
}