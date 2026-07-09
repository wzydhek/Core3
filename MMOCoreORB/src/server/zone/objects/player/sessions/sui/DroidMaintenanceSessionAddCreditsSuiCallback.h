/*
 * DroidMaintenanceSessionRunMenuSuiCallback.h
 *
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/DroidMaintenanceSession.h"

class DroidMaintenanceSessionAddCreditsSuiCallback : public SuiCallback {
public:
	DroidMaintenanceSessionAddCreditsSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
