#include "CityTreasuryDepositSuiCallback.h"
#include "server/zone/managers/city/CityManager.h"

CityTreasuryDepositSuiCallback::CityTreasuryDepositSuiCallback(ZoneServer* server, CityRegion* region) : SuiCallback(server) {
	cityRegion = region;
}

void CityTreasuryDepositSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isTransferBox() || player == nullptr || cancelPressed || args->size() <= 0) {
		return;
	}

	int amount = Integer::valueOf(args->get(0).toString());

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr)
		return;

	Locker lock(city, player);

	CityManager* cityManager = server->getCityManager();
	cityManager->depositToCityTreasury(city, player, amount);
}