#include "CityRegisterSuiCallback.h"

CityRegisterSuiCallback::CityRegisterSuiCallback(ZoneServer* server, CityRegion* city, bool unregister) : SuiCallback(server) {
	cityRegion = city;
	this->unregister = unregister;
}

void CityRegisterSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr || cancelPressed)
		return;

	Locker lock(city, player);

	CityManager* cityManager = server->getCityManager();

	if (unregister) {
		cityManager->unregisterCity(city, player);
	} else {
		cityManager->registerCity(city, player);
	}
}