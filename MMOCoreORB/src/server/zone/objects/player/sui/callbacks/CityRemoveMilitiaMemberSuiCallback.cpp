#include "CityRemoveMilitiaMemberSuiCallback.h"
#include "server/zone/objects/player/sessions/CityRemoveMilitiaSession.h"

CityRemoveMilitiaMemberSuiCallback::CityRemoveMilitiaMemberSuiCallback(ZoneServer* server, CityRegion* city) : SuiCallback(server) {
	cityRegion = city;
}

void CityRemoveMilitiaMemberSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<CityRemoveMilitiaSession*> session = player->getActiveSession(SessionFacadeType::CITYMILITIA).castTo<CityRemoveMilitiaSession*>();

	if (session == nullptr)
		return;

	ManagedReference<CityRegion*> city = cityRegion.get();

	if (city == nullptr || cancelPressed) {
		session->cancelSession();
		return;
	}

	CityManager* cityManager = server->getCityManager();
	cityManager->removeMilitiaMember(city, player, session->getMilitiaID());

	session->cancelSession();
}