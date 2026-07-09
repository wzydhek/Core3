/*
 * PobShipStatusSuiCallback.h
 */

#pragma once

#include "server/zone/Zone.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/ship/PobShipObject.h"

class PobShipStatusSuiCallback : public SuiCallback {
public:
	PobShipStatusSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
