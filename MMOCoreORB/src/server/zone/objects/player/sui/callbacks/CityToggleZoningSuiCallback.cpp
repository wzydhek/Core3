#include "CityToggleZoningSuiCallback.h"
#include "server/zone/managers/city/CityManager.h"
#include "server/zone/objects/player/PlayerObject.h"

CityToggleZoningSuiCallback::CityToggleZoningSuiCallback(ZoneServer* server, CityRegion* city) : SuiCallback(server) {
	cityRegion = city;
}

void CityToggleZoningSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr || !suiBox->isMessageBox() || player == nullptr || cancelPressed) {
		return;
	}

	PlayerObject* ghost = player->getPlayerObject();

	if (ghost == nullptr)
		return;

	if (!city->isMayor(player->getObjectID()) && !ghost->isAdmin()) {
		return;
	}

	if (!player->hasSkill("social_politician_novice") && !ghost->isAdmin()) {
		player->sendSystemMessage("@city/city:zoning_skill"); // You must be a Politician to enable city zoning.
		return;
	}

	Locker clocker(city, player);

	CityManager* cityManager = server->getCityManager();
	cityManager->toggleZoningEnabled(city, player);
}