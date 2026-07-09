#include "CityForceUpdateTypeSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/managers/city/CityManager.h"

CityForceUpdateTypeSuiCallback::CityForceUpdateTypeSuiCallback(ZoneServer* server, CityRegion* city) : SuiCallback(server) {
	cityRegion = city;
}

void CityForceUpdateTypeSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr)
		return;

	if (!suiBox->isMessageBox() || player == nullptr) {
		return;
	}

	PlayerObject* ghost = player->getPlayerObject();

	if (ghost == nullptr)
		return;

	if (!ghost->isPrivileged())
		return;

	Locker clocker(city, player);

	StringIdChatParameter params;
	params.setTO(city->getCityRegionName());

	CityManager* cityManager = server->getCityManager();

	if (cancelPressed) {
		params.setStringId("city/city", "force_city_update"); // Forcing a city update for city %TO.
		cityManager->processCityUpdate(city);
	} else {
		params.setStringId("city/city", "force_city_election"); // Forcing a city update for city %TO.
		cityManager->updateCityVoting(city, true);
	}

	player->sendSystemMessage(params);
}