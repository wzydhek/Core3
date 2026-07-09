#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/eventperk/ShuttleBeacon.h"

class ShuttleBeaconSuiCallback : public SuiCallback {
public:
	ShuttleBeaconSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
