#include "CitySetTaxSuiCallback.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"
#include "server/zone/managers/city/CityManager.h"

CitySetTaxSuiCallback::CitySetTaxSuiCallback(ZoneServer* server, CityRegion* city, int tax) : SuiCallback(server) {
	cityRegion = city;
	taxSelected = tax;
}

void CitySetTaxSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr || !suiBox->isInputBox() || player == nullptr || cancelPressed || args->size() <= 0) {
		return;
	}

	int value = Integer::valueOf(args->get(0).toString());

	CityManager* cityManager = server->getCityManager();
	cityManager->setTax(city, player, taxSelected, value);
}