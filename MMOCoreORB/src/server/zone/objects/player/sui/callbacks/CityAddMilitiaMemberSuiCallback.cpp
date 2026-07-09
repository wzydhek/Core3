#include "CityAddMilitiaMemberSuiCallback.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"
#include "server/zone/managers/city/CityManager.h"

CityAddMilitiaMemberSuiCallback::CityAddMilitiaMemberSuiCallback(ZoneServer* server, CityRegion* city) : SuiCallback(server) {
	cityRegion = city;
}

void CityAddMilitiaMemberSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr)
		return;

	if (!suiBox->isInputBox() || player == nullptr || cancelPressed || args->size() <= 0) {
		return;
	}

	String playerName = args->get(0).toString();

	CityManager* cityManager = server->getCityManager();
	cityManager->addMilitiaMember(city, player, playerName);
}