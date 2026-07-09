/*
 * DroidMaintenanceSessionRunMenuSuiCallback.h
 *
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/DroidMaintenanceSession.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/structure/StructureObject.h"

class DroidMaintenanceSessionRunMenuSuiCallback : public SuiCallback {
public:
	DroidMaintenanceSessionRunMenuSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
