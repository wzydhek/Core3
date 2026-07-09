#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"

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
