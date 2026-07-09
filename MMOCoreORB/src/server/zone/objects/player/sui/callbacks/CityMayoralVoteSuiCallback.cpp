#include "CityMayoralVoteSuiCallback.h"
#include "server/zone/managers/city/CityManager.h"

CityMayoralVoteSuiCallback::CityMayoralVoteSuiCallback(ZoneServer* server, CityRegion* city) : SuiCallback(server) {
	cityRegion = city;
}

void CityMayoralVoteSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr)
		return;

	if (!suiBox->isListBox() || player == nullptr || args->size() <= 0 || cancelPressed)
		return;

	SuiListBox* listbox = cast<SuiListBox*>(suiBox);

	int idx = Integer::valueOf(args->get(0).toString());

	if (idx >= listbox->getMenuSize() || idx < 0)
		return;

	uint64 oid = listbox->getMenuObjectID(idx);

	Locker clocker(city, player);

	CityManager* cityManager = server->getCityManager();
	cityManager->castMayoralVote(city, player, oid);
}