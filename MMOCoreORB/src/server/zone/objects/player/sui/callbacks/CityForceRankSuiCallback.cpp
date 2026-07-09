#include "CityForceRankSuiCallback.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/managers/city/CityManager.h"

CityForceRankSuiCallback::CityForceRankSuiCallback(ZoneServer* server, CityRegion* city, bool rank) : SuiCallback(server) {
	cityRegion = city;
	rankUp = rank;
}

void CityForceRankSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr)
		return;

	if (!suiBox->isMessageBox() || player == nullptr || cancelPressed) {
		return;
	}

	PlayerObject* ghost = player->getPlayerObject();

	if (ghost == nullptr)
		return;

	if (!ghost->isPrivileged())
		return;

	Locker clocker(city, player);

	StringIdChatParameter params("city/city", "force_city_rank"); // Forcing a city rank change for city %TO.
	params.setTO(city->getCityRegionName());
	player->sendSystemMessage(params);

	CityManager* cityManager = server->getCityManager();

	if (rankUp)
		cityManager->expandCity(city);
	else
		cityManager->contractCity(city);
}