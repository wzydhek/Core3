#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class TravelCouponUseSuiCallback : public SuiCallback {
	ManagedReference<SceneObject*> voucher;
	int fare;
	String departurePlanet;
	String departurePoint;
	String arrivalPlanet;
	String arrivalPoint;

public:
	TravelCouponUseSuiCallback(ZoneServer* server, SceneObject* vouch, int travelFare, String departurePl, String departurePo, String arrivalPl, String arrivalPo);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
