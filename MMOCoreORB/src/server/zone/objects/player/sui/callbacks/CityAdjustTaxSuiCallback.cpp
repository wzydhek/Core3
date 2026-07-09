#include "CityAdjustTaxSuiCallback.h"
#include "server/zone/managers/city/CityManager.h"

CityAdjustTaxSuiCallback::CityAdjustTaxSuiCallback(ZoneServer* server, CityRegion* city) : SuiCallback(server) {
	cityRegion = city;
}

void CityAdjustTaxSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr || !suiBox->isListBox() || player == nullptr || cancelPressed || args->size() <= 0) {
		return;
	}

	SuiListBox* listbox = cast<SuiListBox*>(suiBox);

	int idx = Integer::valueOf(args->get(0).toString());

	if (idx > listbox->getMenuSize() - 1 || idx < 0)
		return;

	int taxSelected = listbox->getMenuObjectID(idx);

	CityManager* cityManager = server->getCityManager();
	cityManager->promptSetTax(city, player, taxSelected, listbox->getUsingObject().get());
}