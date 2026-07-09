#include "CityForceUpdateSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/region/CityRegion.h"

CityForceUpdateSuiCallback::CityForceUpdateSuiCallback(ZoneServer* server, CityRegion* city)
	: SuiCallback(server) {
	cityRegion = city;
}

void CityForceUpdateSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
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

	ManagedReference<SuiMessageBox*> box = new SuiMessageBox(player, SuiWindowType::CITY_ADMIN_CONFIRM_UPDATE_TYPE);
	box->setPromptTitle("@city/city:force_city_update_t"); // Force City Update
	box->setPromptText("@city/city:force_election_only");  // Do you only want to force an election?
	box->setCancelButton(true, "@no");
	box->setOkButton(true, "@yes");
	box->setCallback(new CityForceUpdateTypeSuiCallback(server, city));

	ghost->addSuiBox(box);
	player->sendMessage(box->generateMessage());
}
