#include "CityTreasuryWithdrawalSuiCallback.h"

CityTreasuryWithdrawalSuiCallback::CityTreasuryWithdrawalSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void CityTreasuryWithdrawalSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityTreasuryWithdrawalSession*> session = player->getActiveSession(SessionFacadeType::CITYWITHDRAW).castTo<CityTreasuryWithdrawalSession*>();

	if (session == nullptr)
		return;

	if (!suiBox->isTransferBox() || cancelPressed || args->size() <= 1) {
		session->cancelSession();
		return;
	}

	int value = Integer::valueOf(args->get(1).toString());
	session->withdrawCredits(value);
}