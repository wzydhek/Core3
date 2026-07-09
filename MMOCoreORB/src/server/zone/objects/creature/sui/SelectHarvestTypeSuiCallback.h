/*
 * SelectHarvestSuiCallback.h
 *
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/tangible/components/droid/DroidHarvestModuleDataComponent.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

class SelectHarvestSuiCallback : public SuiCallback {
public:
	SelectHarvestSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

};
